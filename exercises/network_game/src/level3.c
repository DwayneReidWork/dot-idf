#include <game/game.h>
#include <game/level3.h>

#include <string.h>
#include <stdlib.h>

#define LEVEL3_PROMPT "[+] level 3: mod your port number by 256 and save it as a uint8_t key.\n - your port number should be in 'host byte order' before you mod it. review documentation (for struct sockaddr_in) if in c. \n - xor each byte of your name by the key and send it back in the following format [uint8_t - key][uint8_t - xor_name size {N}][{N} bytes xor_name]"

int level3_start(game_t *game) {
    int status = -1;
    ssize_t bytes_tx = -1;
    ssize_t message_len = -1;
    uint8_t name_len = 0;
    uint8_t their_key = 0;

    char xor_name[NAME_LENGTH] = {0};
    char name[NAME_LENGTH] = {0};
    char *message = NULL;

    game->key = ntohs(game->port) % 256;
    for (int i = 0; i < strlen(game->name); i++) {
        xor_name[i] = game->name[i] ^ game->key;
    }

    message_len = game_pack_message(LEVEL3_PROMPT, strlen(LEVEL3_PROMPT), &message, NULL);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }
    game_server_prompt(3);

    bytes_tx = game_recv_all(game, (char *)&their_key, sizeof(uint8_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    if (their_key != game->key) {
        goto END;
    }

    bytes_tx = game_recv_all(game, (char *)&name_len, sizeof(uint8_t));
    if (-1 == bytes_tx) {
        goto END;
    }

    if (name_len != strlen(game->name)) {
        goto END;
    }

    bytes_tx = game_recv_all(game, name, name_len);
    if (-1 == bytes_tx) {
        goto END;
    }

    if (0 != strncmp(name, xor_name, name_len))
    {
        goto END;
    }

    status = 0;

END:
    return status;
}
