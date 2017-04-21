#include "./headers/libmy.h"
#include "./headers/my_slack.h"

int			main(/* int argc , char *argv[] */) {
  int			socket_desc;
  int			new_socket;
  int			c;
  struct sockaddr_in	server;
  struct sockaddr_in	client;
  char			*msg;

  /* Create socket */
  if ((socket_desc = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    printf("Could not create socket\n");

  /* Prepare the sockaddr_in structure */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8888 );

  /* Bind */
  if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
    puts("bind failed");
    return 1;
  }
  puts("bind done");

  /* Listen */
  listen(socket_desc , 3);

  /* Accept and incoming connection */
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);
  while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ) {
    puts("Connection accepted");

    /* Reply to the client */
    msg = "Hello Client , I have received your connection. But I have to go now, bye\n";
    write(new_socket , msg , strlen(msg));
  }

  if (new_socket < 0) {
    perror("accept failed");
    return 1;
  }

  return 0;
}
