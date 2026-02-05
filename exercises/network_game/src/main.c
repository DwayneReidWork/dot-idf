#include <game/game.h>
#include <game/level1.h>
#include <game/level2.h>
#include <game/level3.h>
#include <game/level4.h>
#include <game/level5.h>
#include <game/level6.h>
#include <game/level7.h>
#include <game/level8.h>
#include <game/level9.h>

#include <network/network.h>

#include <netinet/in.h>
#include <sys/socket.h>

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define PORT "5000"

int main(int argc, char **argv) {
  game_t game = {0};
  int server_fd = -1;
  int status = 0;
  int running = 1;

  char *port = NULL;
  srand(time(NULL));

  if (1 == argc) {
      printf("[+] no port provided, using default: %s\n", PORT);
      port = PORT;
  } else {
      port = argv[1];
  }

  server_fd = network_tcp_listen(NULL, port);
  if (-1 == server_fd) {
    printf("[X] unable to create tcp listener\n");
    goto END;
  }

  game_greeting(server_fd);


  while (running) {
    game.addr_len = sizeof(struct sockaddr_in);
    game.fd = accept(server_fd, (struct sockaddr *)&game.addr, &game.addr_len);
    if (-1 == game.fd) {
      printf("[X] unable to accept clients\n");
      break;
    }


    status = level1_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level2_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level3_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level4_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level5_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level6_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level7_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level8_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    status = level9_start(&game);
    if (-1 == status) {
        goto CLEANUP;
    }

    printf("[+] You have made it to the end of the levels! check back later for an updated binary\n");
    running = 0;
  CLEANUP:
    game_cleanup(server_fd, &game);
  }

  close(server_fd);

END:
  return 0;
}
