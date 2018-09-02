#include <udp.h>

static inline void checkArgs (int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "\n\tUSAGE:\n\n%s <host> <port>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

#define BUFSIZE 512
char buf[BUFSIZE];

int main (int argc, char** argv) {

  checkArgs(argc, argv);

  int socketFd;
#ifdef SERVER
  socketFd = udpFdBnd(argv[2], 0);       // socket to listen on

  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  ssize_t nread;
  for (;;) {
    peer_addr_len = sizeof(struct sockaddr_storage);
    nread = recvfrom(socketFd, buf, BUFSIZE, 0,
        (struct sockaddr *) &peer_addr, &peer_addr_len);
    printf("%s\n", buf);
  }
#else  // CLIENT
  socketFd = udpFd(argv[1], argv[2], 0); // socket to connect to

  char *msg = "Hello UDP peer";
  write(socketFd, msg, strlen(msg)+1);
#endif // SERVER  
}
