#include <game/level10.h>
#include <game/game.h>

#include <network/network.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LEVEL10_PROMPT "[+] level 10: what a long strange journey it has been. lets make it needlessly complicated. send me your uint16_t array as follows:\n - send in the same sequence I originally sent the array in level 5\n - for each item indexed as [M][N]\n - send the uint16_t item through connection A.\n - accept a temp connection through your listening TCP socket, we will call this temp connection Temp.\n - if M is even send the first 8 bits of the uint16_t to connection B and the second 8 bits through connection Temp, do the opposite if M is odd.\n - if N is even, perform a KEY_SELECT after sending the uint16_t and the two uint8_t.\n - consider 0 even for the conditions described above"

int level10_start(game_t *game) {
    int status = -1;

    char *message = NULL;
    ssize_t message_len = -1;
    ssize_t bytes_tx = -1;

    int temp = -1;

    uint16_t item = 0;
    uint8_t first  = 0;
    uint8_t second = 0;

    uint8_t my_first  = 0;
    uint8_t my_second = 0;

    uint32_t kn = 0;
    uint16_t a = 0;
    uint16_t b = 0;
    uint8_t new_key = 0;


    message_len = game_pack_message(LEVEL10_PROMPT, strlen(LEVEL10_PROMPT), &message, game);
    if (-1 == message_len) {
        goto END;
    }

    bytes_tx = game_send_all(game->fd, message, message_len);
    free(message);
    if (-1 == bytes_tx) {
        goto END;
    }

    game_server_prompt(10);

    for (int m = 0; m < GAME_ARRAY_X; m++) {
        for (int n = 0; n < GAME_ARRAY_Y; n++) {
            memset(&my_first, 0, sizeof(uint8_t));
            memset(&my_second, 0, sizeof(uint8_t));
            memcpy(&my_first, &game->array[m][n], sizeof(uint8_t));
            memcpy(&my_second, ((char *)&game->array[m][n] + sizeof(uint8_t)), sizeof(uint8_t));

            bytes_tx = game_recv_all(game->fd, (char *)&item, sizeof(uint16_t));
            if (-1 == bytes_tx) {
                goto END;
            }

            game_xor_buffer(game, (char *)&item, sizeof(uint16_t));
            item = htons(item);
            if (item != game->array[m][n]) {
                goto END;
            }

            temp = network_tcp_connect("127.0.0.1", game->their_port_str);
            if (0 > temp) {
                goto END;
            }

            if (m == 0 || m % 2 == 0) {
                bytes_tx = game_recv_all(game->fd_2, (char *)&first, sizeof(uint8_t));
                if (-1 == bytes_tx) {
                    goto END;
                }

                game_xor_buffer(game, (char *)&first, sizeof(uint8_t));
                if (first != my_first) {
                    goto END;
                }

                bytes_tx = game_recv_all(temp, (char *)&second, sizeof(uint8_t));
                if (-1 == bytes_tx) {
                    goto END;
                }

                game_xor_buffer(game, (char *)&second, sizeof(uint8_t));
                if (second != my_second) {
                    goto END;
                }
            } else {
                bytes_tx = game_recv_all(temp, (char *)&first, sizeof(uint8_t));
                if (-1 == bytes_tx) {
                    goto END;
                }

                game_xor_buffer(game, (char *)&first, sizeof(uint8_t));
                if (first != my_first) {
                    goto END;
                }

                bytes_tx = game_recv_all(game->fd_2, (char *)&second, sizeof(uint8_t));
                if (-1 == bytes_tx) {
                    goto END;
                }

                game_xor_buffer(game, (char *)&second, sizeof(uint8_t));
                if (second != my_second) {
                    goto END;
                }
            }

            if (0 == n || n % 2 == 0) {
                new_key = game_key_select(game, &kn, &a, &b);
                bytes_tx = game_send_key_select(game, game->fd, kn, a, b);
                if (-1 == bytes_tx) {
                    goto END;
                }

                game->key = new_key;
            }

            if (temp >= 0) {
                close(temp);
                temp = -1;
            }
        }
    }

    status = 0;

END:
    return status;
}
