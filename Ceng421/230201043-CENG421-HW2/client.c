#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

  int simpleSocket = 0;
  int simplePort = 0;
  int returnStatus = 0;
  char buffer[256] = "";
  struct sockaddr_in simpleServer;

  if (3 != argc) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  /* create a streaming socket */
  simpleSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (simpleSocket == -1) {
    fprintf(stderr, "Could not create a socket!\n");
    exit(1);
  } else {
    printf("Socket created!\n");
  }

  /* retrieve the port number for connecting */
  simplePort = atoi(argv[2]);

  /* set up the address structure */
  /* use the IP address argument for the server address */
  bzero(&simpleServer, sizeof(simpleServer));
  simpleServer.sin_family = AF_INET;
  inet_addr(argv[1], &simpleServer.sin_addr.s_addr);
  simpleServer.sin_port = htons(simplePort);

  /* connect to the address and port with our socket */
  returnStatus = connect(simpleSocket,
    (struct sockaddr*) &simpleServer,
    sizeof(simpleServer));

  if (returnStatus == 0) {
    printf("Connect successful!\n");
  } else {
    fprintf(stderr, "Could not connect to address!\n");
    close(simpleSocket);
    exit(1);
  }

  printf("\nnumber1: ");
  scanf("%s", buffer);
  write(simpleSocket, buffer, strlen(buffer));

  printf("\nnumber2: ");
  scanf("%s", buffer);
  write(simpleSocket, buffer, strlen(buffer));

  /* get the message from the server */
  returnStatus = read(simpleSocket, buffer, sizeof(buffer));

  if (returnStatus > 0) {
    printf("result is %s", buffer);
  } else {
    fprintf(stderr, "Return Status = %d\n", returnStatus);
  }

  close(simpleSocket);
  return 0;
}