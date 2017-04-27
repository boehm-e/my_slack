#include "./headers/libmy.h"
#include "./headers/list.h"
#include "./headers/my_slack.h"

int			connected;
t_client		client;

int			main(/* int argc , char *argv[] */) {
  int			socket_desc;
  int			new_socket;
  int			c;
  int			max_conn;
  struct sockaddr_in	addr_client;
  t_client		_client;
  char			client_msg[BUFFER_SIZE];
  fd_set	        my_set;


  if ((socket_desc = create_socket()) == -1)
    return 1;

  max_conn = socket_desc;
  connected = 0;

  /* Accept and incoming connection */
  my_printf("Waiting for incoming connections...\n");
  c = sizeof(struct sockaddr_in);

  while (42) {
    FD_ZERO(&my_set);
    FD_SET(STDIN_FILENO, &my_set);
    FD_SET(socket_desc, &my_set);

    if(connected)
      FD_SET(client.sock, &my_set);

    if(select(max_conn + 1, &my_set, NULL, NULL, NULL) == -1) {
      my_printf("ERROR : Select failed");
      return 1;
    }


    if (FD_ISSET(STDIN_FILENO, &my_set)) {
      if(connected && send(client.sock, client_msg, my_strlen(client_msg), 0) < 0) {
	my_printf("ERROR : Send failed");
	return -1;
      }
    } else if(FD_ISSET(socket_desc, &my_set)) { /* Si le socket est dans l'ensemble */
      if( (new_socket = accept(socket_desc, (struct sockaddr *)&addr_client, (socklen_t*)&c)) )
	my_printf("Connection accepted (%i)\n", new_socket);

      if(recieve_msg(new_socket, client_msg) == -1)
        continue;

      max_conn = new_socket > max_conn ? new_socket : max_conn;
      FD_SET(new_socket, &my_set);

      _client.sock = 0;
      memset(_client.name, 0, my_strlen(_client.name));

      _client.sock = new_socket;
      my_strncpy(_client.name, client_msg, BUFFER_SIZE - 1);
      client = _client;
      connected = 1;

    } else {
      if(FD_ISSET(client.sock, &my_set)) {
	int c = recieve_msg(client.sock, client_msg);
	if (c == 0) {
	  close(client.sock);
	  remove_client(&client);
	  my_printf("Client déconnecté");
	} else {
	  if(connected && send(client.sock, client_msg, my_strlen(client_msg), 0) < 0) {
	    my_printf("ERROR : Send failed");
	    return -1;
	  }

	  /* loop over my_set, and catch calls */
	  /* for(;;) { */
	  /*   select(sock, &my_test, 0, 0, 0); */
	  /*   if(FD_ISSET(socket_desc, &my_test)) { */
	  /*     cli_len = sizeof(cli_addr); */
	  /*     newfd = accept(socket_desc, (struct sockaddr*)&addr_client, (socklen_t *)&c); */
	  /*     close(newfd); */
	  /*   } */

	  /*   for(i = 0; i < sock; ++i) { */
	  /*     if (FD_ISSET(i, &my_test)) { */
	  /* 	close(i); */
	  /* 	FD_CLR(i, &my_test); */
	  /*     } */
	  /*   } */

	}
      }
    }

    if (new_socket < 0) {
      perror("accept failed");
      return 1;
    }
  }

  close(client.sock);
  close(socket_desc);

  return 0;
}


int			create_socket() {
  int			_socket;
  struct sockaddr_in	server;

  /* Create socket */
  if ((_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    my_printf("Could not create socket\n");

  /* Prepare the sockaddr_in structure */
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8080 );

  /* Bind */
  if( bind(_socket,(struct sockaddr *)&server , sizeof(server)) < 0) {
    my_printf("bind failed\b");
    return -1;
  }
  my_printf("bind done\n");

  /* Listen */
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

void			remove_client(t_client *client) {
  memmove(&client, &client + 1, 0);
  connected--;
}
