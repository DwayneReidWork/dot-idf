#include <game/game.h>
#include <game/level7.h>

#include <string.h>
#include <stdlib.h>

#define LEVEL7_PROMPT "[+] level 7: perform the following operations on each item in you array.\n - item = (item + key)\n - item = item mod 4096\n - item = result of xoring each byte of the item by the key.\n - in the future we will call this process `ARRAY_SCRAMBLE`\n\n - send back your array as a 90 byte buffer with array[0][0] being the first item and incrementing in order of [0][1], [0][2], etc."

int level7_start(game_t *game) {
    int status = -1;

    ssize_t bytes_tx = -1;
    ssize_t message_len = -1;
    char *message = NULL;

    uint16_t array[GAME_ARRAY_X][GAME_ARRAY_Y] = {0};

    message_len = game_pack_message(LEVEL7_PROMPT, strlen(LEVEL7_PROMPT), &message, game);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

END:
    return status;
}
