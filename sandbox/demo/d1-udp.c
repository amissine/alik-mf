/*
 * Acknowledgements:
 * - https://github.com/uNetworking/uSockets
 * - https://cs.nyu.edu/~mwalfish/classes/16sp/classnotes/handout01.pdf
 */

#include <udp.h>

#ifdef SERVER
#define ARGC 3
#define USAGE \
  fprintf(stderr, "\n\tUSAGE:\n\n%s <host> <port>\n\n", argv[0]); \
  exit(EXIT_FAILURE);
#else  // CLIENT
#define ARGC 4
#define USAGE \
  fprintf(stderr, "\n\tUSAGE:\n\n%s <host> <port> <msg>\n\n", argv[0]); \
  exit(EXIT_FAILURE);
#endif // SERVER

static inline void checkArgs (int argc, char** argv) {
  if (argc != ARGC) { USAGE }
}

int main (int argc, char** argv) {
  checkArgs(argc, argv);
  int socketFd;
#ifdef SERVER
  socketFd = udpFdBnd(argv[1], argv[2]);
#else  // CLIENT
  socketFd = udpFd(argv[1], argv[2]);
#endif // SERVER  
}
