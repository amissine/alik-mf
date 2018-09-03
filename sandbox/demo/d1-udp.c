#include <udp.h>

static inline void checkArgs (int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "\n\tUSAGE:\n\n%s <host> <port>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }
}

#define BUFSIZE 512
char buf[BUFSIZE];
ssize_t nread;

int main (int argc, char** argv) {

  checkArgs(argc, argv);

  int socketFd;
#ifdef SERVER
  socketFd = udpFdBnd(argv[2], 0);       // socket to listen on

  struct sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  for (;;) {
    peer_addr_len = sizeof(struct sockaddr_storage);
    nread = recvfrom(socketFd, buf, BUFSIZE, 0,
        (struct sockaddr *) &peer_addr, &peer_addr_len);
    if (nread < 0) continue; // ignore failed request

    char host[NI_MAXHOST], service[NI_MAXSERV];
    int s = getnameinfo((struct sockaddr *) &peer_addr, peer_addr_len,
        host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV);
    if (s == 0) printf("Received %d bytes from %s:%s\n", nread, host, service);
    else fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

    if (sendto(socketFd, buf, nread, 0,
          (struct sockaddr *) &peer_addr, peer_addr_len) != nread)
      fprintf(stderr, "Error sending response\n");
  }
#else  // CLIENT
  socketFd = udpFd(argv[1], argv[2], 0); // socket to connect to

  char *msg = "Hello UDP peer";
  int len = strlen(msg)+1;
  if (write(socketFd, msg, len) != len) {
    fprintf(stderr, "partial/failed write\n"); exit(EXIT_FAILURE);
  }

  if ((nread = read(socketFd, buf, BUFSIZE)) < 0) {
    perror("read"); exit(EXIT_FAILURE);
  }
#endif // SERVER  
}
