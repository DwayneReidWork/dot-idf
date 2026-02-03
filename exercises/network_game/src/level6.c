#include <game/level6.h>
#include <game/game.h>

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define LEVEL6_PROMPT "[+] level 6: I hope your array is in order.\n - take array[3][7] and array[4][4] and add them together and then mod the result by 256.\n - that is going to be the new xor key.\n - send back the correct new key xor'd with the old key, then use the new key from here on out"

int level6_start(game_t *game) {
    int status = -1;

    uint8_t their_key = 0;
    uint8_t new_key = 0;

    char *prompt = LEVEL6_PROMPT;
    char *message = NULL;
    ssize_t message_length = -1;
    ssize_t bytes_tx = -1;

    new_key = (game->array[3][7] + game->array[4][4]) % 256;

    message_length = game_pack_message(prompt, strlen(prompt), &message, game);
    if (-1 == message_length) {
        goto END;
    }

    bytes_tx = game_send_all(game, message, message_length);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

    bytes_tx = game_recv_all(game, (char *)&their_key, sizeof(uint8_t));
    if (-1 == bytes_tx) {
        goto END;
    }
    game_xor_buffer(game, (char *)&their_key, sizeof(uint8_t));
    if (their_key == new_key) {
        game->key = new_key;
        status = 0;
    }


END:
    return status;
}
