#include <game/level8.h>
#include <game/game.h>

#include <stdlib.h>
#include <string.h>

#define LEVEL8_PROMPT "[+] level 8: implement a new procedure called KEY_SELECT that will:\n - recv a uint32_t {N}\n - perform an ARRAY_SCRAMBLE N times\n - recv two uint16_t, A then B.\n - index your uint16_t array by [A % 5][B % 9]\n - mod the indexed value by 256 and save that as the new xor key\n\n - perform a KEY_SELECT and respond with the new key"

int level8_start(game_t *game) {
    int status = -1;
    uint8_t temp_key = 0;
    uint32_t n = 0;
    uint16_t a = 0;
    uint16_t b = 0;

    char *message = NULL;
    size_t message_len = 0;

    temp_key = game_key_select(game, &n, &a, &b);
    n = htonl(n);
    a = htons(a);
    b = htons(b);

    message_len = game_pack_message(LEVEL8_PROMPT, strlen(LEVEL8_PROMPT), &message, game);
    game_send_all(game->fd, message, message_len);
    free(message);
    game_server_prompt(8);

    game_xor_buffer(game, (char *)&n, sizeof(uint32_t));
    game_xor_buffer(game, (char *)&a, sizeof(uint16_t));
    game_xor_buffer(game, (char *)&b, sizeof(uint16_t));

    game_send_all(game->fd, (char *)&n, sizeof(uint32_t));
    game_send_all(game->fd, (char *)&a, sizeof(uint16_t));
    game_send_all(game->fd, (char *)&b, sizeof(uint16_t));

    game->key = temp_key;
    temp_key = 0;

    game_recv_all(game->fd, (char *)&temp_key, sizeof(uint8_t));
    game_xor_buffer(game, (char *)&temp_key, sizeof(uint8_t));

    if (temp_key == game->key) {
        status = 0;
    }

END:
    return status;
}
