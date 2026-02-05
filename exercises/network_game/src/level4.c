#include <game/level4.h>

#include <stdlib.h>
#include <string.h>

#define LEVEL4_PROMPT "[+] level 4: all messages after this message will be fully xor'd with our shared key.\n - Immediately following this message, an xor'd message will be set with your next requirement.\n - send all further responses to the server xor'd with our shared key.\n - This is a regular GAME_MESSAGE, but the entire GAME_MESSAGE buffer has been xor'd before being sent.\n - This means that after reading a uint32_t, it needs to be xor'd then converted from network byte order to host byte order."

#define LEVEL4_CLEAR_PROMPT "[+] level 4: hopefully this message gets through! I am sending you two uint32_t, add them together and send them back to me.\n - Remember that these two uint32_t have been xor'd AFTER being converted to network byte order.\n - Remember, to conver your result to network byte order then xor your result"

int level4_start(game_t *game) {
    int status = -1;

    char *xor_prompt = NULL;
    ssize_t xor_prompt_len = strlen(LEVEL4_CLEAR_PROMPT);

    char *message = NULL;
    ssize_t message_len = -1;
    ssize_t bytes_tx = -1;

    uint32_t a = rand() % 10000;
    uint32_t b = rand() % 10000;

    uint32_t sum = a + b;
    uint32_t their_sum = 0;

    if (NULL == game) {
        goto END;
    }

    xor_prompt = calloc(xor_prompt_len, sizeof(char));
    memcpy(xor_prompt, LEVEL4_CLEAR_PROMPT, xor_prompt_len);

    message_len = game_pack_message(LEVEL4_PROMPT, strlen(LEVEL4_PROMPT), &message, NULL);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game->fd, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

    message_len = game_pack_message(xor_prompt, xor_prompt_len, &message, game);
    free(xor_prompt);

    bytes_tx = game_send_all(game->fd, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

    game_server_prompt(4);

    a = htonl(a);
    b = htonl(b);
    game_xor_buffer(game, (char *)&a, sizeof(uint32_t));
    game_xor_buffer(game, (char *)&b, sizeof(uint32_t));

    game_send_all(game->fd, (char *)&a, sizeof(uint32_t));
    game_send_all(game->fd, (char *)&b, sizeof(uint32_t));

    game_recv_all(game->fd, (char *)&their_sum, sizeof(uint32_t));
    game_xor_buffer(game, (char *)&their_sum, sizeof(uint32_t));

    their_sum = ntohl(their_sum);

    if (their_sum == sum) {
        status = 0;
    }

END:
    return status;
}
