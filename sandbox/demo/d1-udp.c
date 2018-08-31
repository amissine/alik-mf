/*
 * Acknowledgements:
 * - https://github.com/uNetworking/uSockets
 * - https://cs.nyu.edu/~mwalfish/classes/16sp/classnotes/handout01.pdf
 * - https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
 */

#include <udp.h>

static inline void checkArgs (int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "\n\tUSAGE:\n\n%s <host> <port>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

int main (int argc, char** argv) {

  checkArgs(argc, argv);

  int socketFd;
#ifdef SERVER
  socketFd = udpFdBnd(argv[1], argv[2]); // socket to listen on
#else  // CLIENT
  socketFd = udpFd(argv[1], argv[2]);    // socket to write to
#endif // SERVER  
}
