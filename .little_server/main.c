#include "./headers/libmy.h"
#include "./headers/list.h"
#include "./headers/my_slack.h"

int			main(/* int argc , char *argv[] */) {
  int			socket_desc;
  int			new_socket;
  int			_c;
  int			read_size;
  struct sockaddr_in	addr_client;
  char			client_msg[BUFFER_SIZE];


  if ((socket_desc = create_socket()) == -1)
    return 1;

  my_printf("Waiting for incoming connections...\n");
  _c = sizeof(struct sockaddr_in);

  while (42) {
    if ( (new_socket = accept(socket_desc, (struct sockaddr *)&addr_client, (socklen_t*)&_c)) ) {
      my_printf("Connection accepted\n");
    }

    if( (read_size = recv(new_socket , client_msg , BUFFER_SIZE , 0)) > 0 ) {
      my_printf("MESSAGE RECIEVED : %s\n", client_msg);

      write(new_socket , client_msg , my_strlen(client_msg));
      memset(client_msg, 0, my_strlen(client_msg));
    }
    my_printf("...");
  }

  if (new_socket < 0) {
    perror("accept failed");
    return 1;
  }
  close(socket_desc);
  return 0;
}


int			create_socket() {
  int			_socket;
  struct sockaddr_in	server;

  if ((_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    my_printf("Could not create socket\n");

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8080 );

  if( bind(_socket,(struct sockaddr *)&server , sizeof(server)) < 0) {
    my_printf("bind failed\b");
    return 1;
  }
  my_printf("bind done\n");

  listen(_socket , 3);
  return _socket;
}

int			recieve_msg(int _socket, char *msg) {
  int			n;

  n = 0;
  if((n = recv(_socket, msg, BUFFER_SIZE - 1, 0)) < 0) {
    my_printf(" ERROR : recv()");
    n = 0;
  }

  my_printf("RECIEVE MESSAGE : %s\n", msg);

  /* send back client's message */
  write(_socket , msg , my_strlen(msg));
  memset(msg, 0, my_strlen(msg));

  msg[n] = 0;
  return n;
}

int			send_msg(int _socket, char *msg) {
  if(send(_socket, msg, my_strlen(msg), 0) < 0) {
      my_printf(" ERROR : send()");
      exit(-1);
    }
  return 0;
}
