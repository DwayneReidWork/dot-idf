#ifndef __GAME__GAME_H
#define __GAME__GAME_H

#include <stdint.h>

#include <netinet/in.h>

#define NAME_LENGTH 256
#define GAME_ARRAY_X 5
#define GAME_ARRAY_Y 9

typedef struct _game {
  int fd;
  char name[NAME_LENGTH];
  uint16_t port;
  uint16_t array[GAME_ARRAY_X][GAME_ARRAY_Y];
  struct sockaddr_in addr;
  socklen_t addr_len;
  uint8_t key;
} game_t;

void game_greeting(int fd);

void game_cleanup(int fd, game_t *game);

ssize_t game_pack_message(char *message, size_t message_size, char **dst, game_t *xor);

ssize_t game_send_all(game_t *game, char *message, size_t message_len);

ssize_t game_recv_all(game_t *game, char *message, size_t message_len);

void game_xor_buffer(game_t *game, char *buffer, size_t buffer_len);

#endif
