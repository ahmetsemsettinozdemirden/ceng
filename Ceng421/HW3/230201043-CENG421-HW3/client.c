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

  if (3 != argc) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  /* SSL configuration */
  SSL_METHOD *method;
  SSL_CTX *ctx;
  SSL *ssl;

  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();
  method = TLSv1_client_method();
  ctx = SSL_CTX_new(method);
  if (ctx == NULL) {
    ERR_print_errors_fp(stderr);
    exit(1);
  }

  /* Socket configuration */
  int simpleSocket = 0;
  int simplePort = 0;
  int returnStatus = 0;
  char buffer[256] = "";
  struct sockaddr_in simpleServer;

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

  /* Setup secure communication */
  ssl = SSL_new(ctx);
  SSL_set_fd(ssl, simpleSocket);

  if(SSL_connect(ssl) == FAIL){
    ERR_print_errors_fp(stderr);
  } else {
    printf("Connected with %s encryption\n", SSL_get_cipher(ssl));
    
    while(1) {
      printf("\nmessage: ");
      scanf("%s", buffer);
      SSL_write(ssl, buffer, strlen(buffer));

      if(strcmp(buffer, "QUIT") == 0) {
        break;
      }

      /* get the message from the server */
      returnStatus = SSL_read(ssl, buffer, sizeof(buffer));

      if (returnStatus > 0) {
        printf("received: %s\n", buffer);
      } else {
        ERR_print_errors_fp(stderr);
        fprintf(stderr, "\nReturn Status = %d", returnStatus);
      }

      memset(buffer, 0, sizeof(buffer));
    }
  }

  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(simpleSocket);
  return 0;
}