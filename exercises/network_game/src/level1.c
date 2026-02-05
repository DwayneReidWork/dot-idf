#include <game/game.h>
#include <game/level1.h>

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define LEVEL1_PROMPT "[+] level 1: respond with your name in the format of [uint8_t - size {N}][{N} bytes - name]. max name length is 255"

int level1_start(game_t *game) {
    int status = -1;

    char *message = NULL;
    ssize_t size = -1;
    ssize_t bytes_tx = -1;

    uint8_t name_len = 0;

    if (NULL == game) {
        goto END;
    }

    game_server_prompt(1);
    size = game_pack_message(LEVEL1_PROMPT, strlen(LEVEL1_PROMPT), &message, NULL);
    if (-1 == size) {
        goto END;
    }

    bytes_tx = game_send_all(game->fd, message, size);
    if (-1 == bytes_tx) {
        goto END;
    }

    free(message);

    bytes_tx = game_recv_all(game->fd, (char *)&name_len, sizeof(uint8_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    if (name_len > 255) {
        goto END;
    }

    bytes_tx = game_recv_all(game->fd, game->name, name_len);
    if (-1 == bytes_tx) {
        goto END;
    }

    status = 0;

END:
    return status;
}
