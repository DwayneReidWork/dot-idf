#include <game/game.h>
#include <game/level2.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LEVEL2_PROMPT "[+] level 2: welcome %s, respond with your sockets local port. use getsockname to inspect your local socket or file descriptor and respond in the following format [uint16_t - port].\n - remember that uint16_t are multibyte integers and require switching the endianess to network"

int level2_start(game_t *game) {
    int status = -1;

    char *message = NULL;
    char *buffer = NULL;
    uint32_t buffer_len = 0;
    ssize_t bytes_tx = -1;
    ssize_t message_len = -1;

    if (NULL == game || 0 > game->fd) {
        goto END;
    }

    buffer_len = strlen(LEVEL2_PROMPT) + NAME_LENGTH;
    buffer = calloc(buffer_len, sizeof(char));
    if (NULL == buffer) {
        goto END;
    }

    snprintf(buffer, buffer_len, LEVEL2_PROMPT, game->name);

    message_len = game_pack_message(buffer, strlen(buffer), &message, NULL);
    free(buffer);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

    bytes_tx = game_recv_all(game, (char *)&game->port, sizeof(uint16_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    if (game->port == game->addr.sin_port) {
        status = 0;
    }

END:
    return status;
}
