#include <game/game.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void game_greeting(int fd) {
    socklen_t socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in sockaddr = {0};
    char local_ip[INET_ADDRSTRLEN] = {0};

    getsockname(fd, (struct sockaddr *)&sockaddr, &socklen);

    inet_ntop(AF_INET, &sockaddr.sin_addr, local_ip, socklen);

    printf("[+] Welcome v0.5.0\n\n");
    printf("[+] Rules:\n- network messages are NOT null terminated\n- all integer types are in network byte order\n- uint8_t are single byte, and their order does not change\n- the default message format, or GAME_MESSAGE, is [uint32_t - size {N}][{N} bytes - message]\n- if not specified, messages from the server will be in that format\n- if a correct response (format and content) is received, another message will be sent\n- asside from this welcome prompt, all communication will be through a TCP connection\n\n");
    printf("[!] This server is listening on %s:%d\n", local_ip, ntohs(sockaddr.sin_port));
}

void game_cleanup(int fd, game_t *game) {
    socklen_t socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in sockaddr = {0};
    char local_ip[INET_ADDRSTRLEN] = {0};

    getsockname(fd, (struct sockaddr *)&sockaddr, &socklen);

    inet_ntop(AF_INET, &sockaddr.sin_addr, local_ip, socklen);

    printf("[!] game session closed. please reconnect on %s:%d\n", local_ip, ntohs(sockaddr.sin_port));
    shutdown(game->fd, SHUT_RDWR);
    close(game->fd);
    memset(game, 0, sizeof(game_t));
}

ssize_t game_pack_message(char *message, size_t message_size, char **dst, game_t *xor) {
    ssize_t dst_size = -1;
    uint32_t nbo_size = 0;

    if (NULL == message || 0 == message_size || NULL == dst) {
        goto END;
    }

    *dst = (char *)calloc(message_size + sizeof(uint32_t), sizeof(char));
    if (NULL == *dst) {
        goto END;
    }

    nbo_size = htonl(message_size);
    memcpy(*dst, &nbo_size, sizeof(uint32_t));
    memcpy(*dst + sizeof(uint32_t), message, message_size);
    dst_size = sizeof(uint32_t) + message_size;

    if (NULL != xor) {
        game_xor_buffer(xor, *dst, dst_size);
    }

END:
    return dst_size;
}

ssize_t game_send_all(game_t *game, char *message, size_t message_len) {
    ssize_t delta = -1;
    ssize_t bytes_tx = 0;

    if (NULL == game || NULL == message || 0 == message_len || game->fd < 0) {
        goto END;
    }

    while (bytes_tx != message_len) {
        delta = send(game->fd, message + bytes_tx, message_len - bytes_tx, 0);
        if (-1 == delta || 0 == delta) {
            bytes_tx = -1;
            goto END;
        }

        bytes_tx += delta;
    }

END:
    return bytes_tx;
}

ssize_t game_recv_all(game_t *game, char *message, size_t message_len) {
    ssize_t delta = -1;
    ssize_t bytes_tx = 0;

    if (NULL == game || NULL == message || 0 == message_len || game->fd < 0) {
        goto END;
    }

    while (bytes_tx != message_len) {
        delta = recv(game->fd, message + bytes_tx, message_len - bytes_tx, 0);
        if (-1 == delta || 0 == delta) {
            bytes_tx = -1;
            goto END;
        }

        bytes_tx += delta;
    }

END:
    return bytes_tx;
}

void game_xor_buffer(game_t *game, char *buffer, size_t buffer_len) {
    if (NULL == game || NULL == buffer || 0 == buffer_len) {
        return;
    }

    for (int i = 0; i < buffer_len; i++) {
        buffer[i] = buffer[i] ^ game->key;
    }
}
