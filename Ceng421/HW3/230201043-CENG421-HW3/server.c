#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define FAIL    -1

int main(int argc, char *argv[]) {

  if (2 != argc) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  /* SSL Configuration */
  SSL_METHOD *method;
  SSL_CTX *ctx;

  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();
  method = TLSv1_server_method();
  ctx = SSL_CTX_new(method);
  if (ctx == NULL) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  /* Load Certificates*/
  char* certFile = "server.pem";
  char* keyFile = "server.pem";
  SSL_CTX_use_certificate_file(ctx, certFile, SSL_FILETYPE_PEM);
  SSL_CTX_use_PrivateKey_file(ctx, keyFile, SSL_FILETYPE_PEM);
  
  /* verify private key */
  if (!SSL_CTX_check_private_key(ctx)) {
    fprintf(stderr, "Private key does not match the public certificate\n");
    exit(1);
  }

  /* Socket Configuration */
  int simpleSocket = 0;
  int simplePort = 0;
  int returnStatus = 0;
  struct sockaddr_in simpleServer;

  /* create a streaming socket */
  simpleSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

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
    SSL *ssl;
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

    /* Setup secure communication */
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, simpleChildSocket);

    if (SSL_accept(ssl) == FAIL) {
      ERR_print_errors_fp(stderr);
    } else {
      printf("version: %s, cipher: %s\n", SSL_get_version(ssl), SSL_get_cipher(ssl));
      
      while(1) {
        /* read message from client */
        returnStatus = SSL_read(ssl, buffer, sizeof(buffer));
        
        if (returnStatus > 0) {
          fprintf(stderr, "Message arrived: %s\n", buffer);
        } else {
          fprintf(stderr, "Return Status = %d\n", returnStatus);
          break;
        }

        if(strcmp(buffer, "QUIT") == 0) {
          fprintf(stderr, "Client disconnected!\n");
          break;
        }

        /* handle the new connection request */
        /* write out our message to the client */
        fprintf(stderr, "Sending message: %s\n", buffer);
        SSL_write(ssl, buffer, strlen(buffer));
        memset(buffer, 0, sizeof(buffer));
      }
    }

    SSL_free(ssl);
    close(simpleChildSocket);
  }

  SSL_CTX_free(ctx);
  close(simpleSocket);
  return 0;
}