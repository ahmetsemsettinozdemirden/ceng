#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

  int simpleSocket = 0;
  int simplePort = 0;
  int returnStatus = 0;
  struct sockaddr_in simpleServer;

  if (2 != argc) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  /* create a streaming socket */
  simpleSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (simpleSocket == -1) {
    fprintf(stderr, "Could not create a socket!\n");
    exit(1);
  } else {
    fprintf(stderr, "Socket created!\n");
  }

  /* retrieve the port number for listening */
  simplePort = atoi(argv[1]);

  /* set up the address structure */
  /* use INADDR_ANY to bind to all local addresses */
  bzero(&simpleServer, sizeof(simpleServer));
  simpleServer.sin_family = AF_INET;
  simpleServer.sin_addr.s_addr = htonl(INADDR_ANY);
  simpleServer.sin_port = htons(simplePort);

  /* bind to the address and port with our socket */
  returnStatus = bind(simpleSocket,
    (struct sockaddr*) &simpleServer,
    sizeof(simpleServer));

  if (returnStatus == 0) {
    fprintf(stderr, "Bind completed!\n");
  } else {
    fprintf(stderr, "Could not bind to address!\n");
    close(simpleSocket);
    exit(1);
  }

  /* let's listen on the socket for connections */
  returnStatus = listen(simpleSocket, 5);

  if (returnStatus == -1) {
    fprintf(stderr, "Cannot listen on socket!\n");
    close(simpleSocket);
    exit(1);
  }

  while (1) {
    struct sockaddr_in clientName = { 0 };
    int simpleChildSocket = 0;
    char buffer[256] = "";
    int clientNameLength = sizeof(clientName);

    /* wait here */
    simpleChildSocket = accept(simpleSocket, (struct sockaddr*) &clientName, &clientNameLength);

    if (simpleChildSocket == -1) {
      fprintf(stderr, "Cannot accept connections!\n");
      close(simpleSocket);
      exit(1);
    } else {
      fprintf(stderr, "Client connected!\n");
    }

    int num1 = 0;
    int num2 = 0;

    /* get the first number from the client */
    returnStatus = read(simpleChildSocket, buffer, sizeof(buffer));

    if (returnStatus > 0) {
      fprintf(stderr, "\nfirst number is %s", buffer);
      num1 = atoi(buffer);
    } else {
      fprintf(stderr, "Return Status = %d\n", returnStatus);
    }

    /* get the second number from the client */
    returnStatus = read(simpleChildSocket, buffer, sizeof(buffer));

    if (returnStatus > 0) {
      fprintf(stderr, "\nsecond number is %s", buffer);
      num2 = atoi(buffer);
    } else {
      fprintf(stderr, "Return Status = %d\n", returnStatus);
    }

    /* handle the new connection request */
    /* write out our message to the client */
    int result = num1 + num2;
    sprintf(buffer, "%d", result);
    fprintf(stderr, "\nresult is %s", buffer);
    write(simpleChildSocket, buffer, strlen(buffer));
    close(simpleChildSocket);
  }

  close(simpleSocket);
  return 0;
}