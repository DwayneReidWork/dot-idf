#include <game/level9.h>

#include <game/game.h>
#include <network/network.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL9_PROMPT "[+] level 9: implement a TCP listener and respond with your listening port as a uint16_t.\n - AFTER sending your port through THIS connection (connection A), accept a connection (connection B).\n - capture the sockaddr information on the accept call and send me my port (uint16_t) through connection B.\n - Finally, perform a KEY_SELECT\n - unless specified, KEY_SELECT parameters will always be sent through connection A\n - hint: if using C, the uint16_t port captured by the accept call is already in network byte order"

int level9_start(game_t *game) {
    int status = -1;

    uint32_t n = 0;
    uint16_t a = 0;
    uint16_t b = 0;
    uint16_t their_port = 0;
    uint16_t my_port = 0;
    uint8_t new_key = 0;

    ssize_t bytes_tx = 0;

    struct sockaddr_in addr = {0};
    socklen_t socklen = sizeof(struct sockaddr_in);

    char *message = NULL;
    ssize_t message_len = game_pack_message(LEVEL9_PROMPT, strlen(LEVEL9_PROMPT), &message, game);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game->fd, message, message_len);
    if (-1 == bytes_tx) {
        goto END;
    }

    game_server_prompt(9);
    free(message);

    bytes_tx = game_recv_all(game->fd, (char *)&their_port, sizeof(uint16_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    game_xor_buffer(game, (char *)&their_port, sizeof(uint16_t));
    their_port = htons(their_port);

    snprintf(game->their_port_str, 5, "%d", their_port);

    game->fd_2 = network_tcp_connect("127.0.0.1", game->their_port_str);
    if (-1 == game->fd_2) {
        goto END;
    }

    game_recv_all(game->fd_2, (char *)&my_port, sizeof(uint16_t));
    game_xor_buffer(game, (char *)&my_port, sizeof(uint16_t));

    getsockname(game->fd_2, (struct sockaddr *)&addr, &socklen);

    if (addr.sin_port == my_port)
    {
        status = 0;
    }

    new_key = game_key_select(game, &n, &a, &b);
    status = game_send_key_select(game, game->fd, n, a, b);

    game->key = new_key;


END:
    return status;
}
