#include "./headers/libmy.h"
#include "./headers/my_slack.h"
#include <netinet/in.h>
#include <sys/types.h>

int                     main(/* int argc, char **argv */) {
  int                   socket_desc;
  fd_set                my_set;
  char                  buf[BUFFER_SIZE];
  char                  buf2[BUFFER_SIZE];

  memset(buf,'\0', BUFFER_SIZE);
  memset(buf2,'\0', BUFFER_SIZE);

  socket_desc = init_socket();

  while (42) {
    memset(buf, '\0', BUFFER_SIZE);
    memset(buf2, '\0', BUFFER_SIZE);

    FD_ZERO(&my_set);
    FD_SET(0, &my_set);
    FD_SET(socket_desc, &my_set);

    if(select(socket_desc + 1, &my_set, NULL, NULL, NULL) == -1){
      my_printf("ERROR [select]");
      return 1;
    }

    if (FD_ISSET(0, &my_set)) {
      if (read(0, buf2, BUFFER_SIZE) == -1){
        my_printf("ERROR [read]");
        return 1;
      }
      if (send(socket_desc, buf2, BUFFER_SIZE, 0) == -1){
        my_printf("ERROR [send]");
        return 1;
      }
    }
    if (FD_ISSET(socket_desc, &my_set)){
      if (recv(socket_desc, &buf, BUFFER_SIZE, 0) == -1){
        my_printf("Erreur lors de la reception");
        return 1;
      }
      my_printf("BUFFER FROM SERVER: %s\n ", buf);
    }
  }
}

int             init_socket() {
  t_sockaddr_in server;
  int           socket_desc;

  socket_desc = socket(AF_INET , SOCK_STREAM , 0);

  if (socket_desc == -1)
    printf("Could not create socket");

  server.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Erwan : 172.16.16.162 */
  server.sin_family = AF_INET;
  server.sin_port = htons( 8080 );

  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
    my_printf("connect error");
    return 1;
  }
  my_printf("Connected\n");
  return socket_desc;
}
