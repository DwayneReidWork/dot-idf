#include <game/game.h>
#include <game/level5.h>

#include <stdlib.h>
#include <string.h>

#define LEVEL5_PROMPT "[+] level 5: you've made it this far. it only gets harder! I am sending you the data for an uint16_t array of size [5][9].\n - I will send array[0][0-9], then array[1][0-9], and so forth.\n - sum the values in the array and send it back as a uint16_t"

int level5_start(game_t *game)
{
    int status = -1;
    uint16_t sum = 0;
    uint16_t their_sum = 0;

    ssize_t message_len = -1;
    ssize_t bytes_tx = -1;

    uint16_t array[GAME_ARRAY_X][GAME_ARRAY_Y] = {0};

    char *buffer = calloc(strlen(LEVEL5_PROMPT), sizeof(char));
    memcpy(buffer, LEVEL5_PROMPT, strlen(LEVEL5_PROMPT));

    char *message = NULL;

    for (int i = 0; i < GAME_ARRAY_X; i++) {
        for (int j = 0; j < GAME_ARRAY_Y; j++) {
            game->array[i][j] = rand() % 1234;
            array[i][j] = game->array[i][j];
            array[i][j] = htons(array[i][j]);
            sum += game->array[i][j];
        }
    }

    message_len = game_pack_message(buffer, strlen(LEVEL5_PROMPT), &message, game);
    free(buffer);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game, message, message_len);
    free(message);
    message = NULL;
    if (-1 == bytes_tx) {
        goto END;
    }

    game_xor_buffer(game, (char *)array, (GAME_ARRAY_X * GAME_ARRAY_Y) * sizeof(uint16_t));
    bytes_tx = game_send_all(game, (char *)array, (GAME_ARRAY_X * GAME_ARRAY_Y) * sizeof(uint16_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    bytes_tx = game_recv_all(game, (char *)&their_sum, sizeof(uint16_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    game_xor_buffer(game, (char *)&their_sum, sizeof(uint16_t));
    their_sum = ntohs(their_sum);
    if (their_sum == sum) {
        status = 0;
    }

END:
    return status;
}
