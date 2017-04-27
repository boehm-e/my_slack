#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>

#include "./headers/my_slack.h"
#include "./headers/libmy.h"

int			main(/* int argc , char *argv[] */) {
  int			addrlen;
  int			master_socket;
  int			new_socket;
  int			client_socket[30];
  int			activity;
  int			sd;
  int			max_sd;
  struct sockaddr_in	address;
  fd_set	        readfds;

  new_socket = 0;
  master_socket = init(client_socket, &address, &addrlen);

  while(TRUE) {
    reinit_socket(&readfds, master_socket, client_socket, &sd, &max_sd);
    activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

    if (activity < 0)
      my_printf("select error\n");

    if (FD_ISSET(master_socket, &readfds))
      handle_incoming_connexion(master_socket, new_socket, client_socket, address, addrlen);

    handle_socket_set_IO(&readfds, client_socket, &sd, address, addrlen);
  }

  return 0;
}


int			init(int *client_socket, struct sockaddr_in *_address, int *_addrlen) {
  int			master_socket;
  struct sockaddr_in	address;
  int			max_clients;
  int			i;

  max_clients = 30;
  address = *_address;

  /* initialise all client_socket[] to 0 so not checked */
  for (i = 0; i < max_clients; i++)
    client_socket[i] = 0;

  /* create the main socket (master) */
  if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
    my_printf("ERROR during 'socket' !\n failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  /* bind the socket to localhost port 8888 */
  if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
    my_printf("ERROR during 'bind' !\n failed");
    exit(EXIT_FAILURE);
  }
  my_printf("Listener on port %d \n", PORT);

  /* try to specify maximum of 3 pending connections for the master socket */
  if (listen(master_socket, 3) < 0) {
    my_printf("ERROR during 'listen' !\n");
    exit(EXIT_FAILURE);
  }
  *_addrlen = sizeof(address);
  my_printf("Waiting for connections ...\n");

  return master_socket;
}


void			reinit_socket(fd_set *readfds, int master_socket, int *client_socket, int *sd, int *max_sd) {
  int			i;
  int			max_clients;

  max_clients = 30;
  FD_ZERO(readfds); /* clear the socket set */
  FD_SET(master_socket, readfds); /* add master socket to set */
  *max_sd = master_socket;

  /* add child sockets to set */
  for ( i = 0 ; i < max_clients ; i++) {
    *sd = client_socket[i]; /* socket descriptor */

    if(*sd > 0) /* socket descriptor is valid */
      FD_SET(*sd , readfds);

    if(*sd > *max_sd)
      *max_sd = *sd;
  }

}

void			handle_incoming_connexion(int master_socket, int new_socket, int *client_socket, struct sockaddr_in address, socklen_t addrlen) {
  int			i;
  int			max_clients;
  char			*message = "The server has successfully recieved your message !\n";

  max_clients = 30;
  if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    my_printf("ERROR during 'accept' !\n");
    exit(EXIT_FAILURE);
  }

  /* inform user of socket number - used in send and receive commands */
  my_printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

  /* send new connection greeting message */
  if( (int) send(new_socket, message, strlen(message), 0) != (int) strlen(message) )
    my_printf("ERROR during 'send' !\n");

  puts("Welcome message sent successfully");

  /* add new socket to array of sockets */
  for (i = 0; i < max_clients; i++) {
    /* if position is empty */
    if( client_socket[i] == 0 ) {
      client_socket[i] = new_socket;
      my_printf("Adding to list of sockets as %d\n" , i);

      break;
    }
  }
}


void			handle_socket_set_IO(fd_set *readfds, int *client_socket, int *sd, struct sockaddr_in address, socklen_t addrlen) {
  int			i;
  int			max_clients;
  int			valread;
  char			buffer[1024];

  max_clients = 30;
  for (i = 0; i < max_clients; i++) {
    *sd = client_socket[i];

    if (FD_ISSET( *sd , readfds)) {
      /* Check if it was for closing , and also read the incoming message */
      if ((valread = read( *sd , buffer, 1024)) == 0) {
	/* Somebody disconnected , get his details and print */
	getpeername(*sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);
	my_printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

	/* Close the socket and mark as 0 in list for reuse */
	close(*sd);
	client_socket[i] = 0;
      } else { /* Echo back the message that came in */
	buffer[valread] = '\0';
	send(*sd , buffer , strlen(buffer) , 0 );
      }
    }
  }

}
