#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>

#include "./headers/my_slack.h"
#include "./headers/libmy.h"

#include <stdlib.h>
#include <stdarg.h>

int			main(/* int argc , char *argv[] */) {
  int			addrlen;
  int			master_socket;
  int			new_socket;
  t_client		client_socket[30];
  int			activity;
  int			sd;
  int			max_sd;
  struct sockaddr_in	address;
  fd_set		my_set;
  char			buffer[BUFFER_SIZE];

  new_socket = 0;
  master_socket = init(client_socket, &address, &addrlen);

  while(TRUE) {
    reinit_socket(&my_set, master_socket, client_socket, &sd, &max_sd);
    activity = select( max_sd + 1 , &my_set , NULL , NULL , NULL);

    if (activity < 0)
    my_printf("select error\n");

    if (FD_ISSET(master_socket, &my_set))
    handle_incoming_connexion(master_socket, new_socket, client_socket, buffer, address, addrlen);

    handle_socket_set_IO(&my_set, client_socket, buffer, &sd);
  }

  return 0;
}


int			init(t_client *client_socket, struct sockaddr_in *_address, int *_addrlen) {
  int			master_socket;
  struct  sockaddr_in	address;
  int			max_clients;
  int			i;
  int                   enable;

  enable  = 1;

  max_clients = 30;
  address = *_address;

  for (i = 0; i < max_clients; i++) {
    client_socket[i].sock = 0;
    client_socket[i].message_count = 0;
  }

  if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
    my_printf("ERROR during 'socket' !\n failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
    my_printf("ERROR during 'bind' !\n failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
    my_printf("setsockopt(SO_REUSEADDR) failed");
    exit(EXIT_FAILURE);
  }


  my_printf("Listener on port %d \n", PORT);

  if (listen(master_socket, 3) < 0) {
    my_printf("ERROR during 'listen' !\n");
    exit(EXIT_FAILURE);
  }
  *_addrlen = sizeof(address);
  my_printf("Waiting for connections ...\n");

  return master_socket;
}


void			reinit_socket(fd_set *my_set, int master_socket, t_client *client_socket, int *sd, int *max_sd) {
  int			i;
  int			max_clients;

  max_clients = 30;
  FD_ZERO(my_set);
  FD_SET(master_socket, my_set);
  *max_sd = master_socket;

  for (i = 0 ; i < max_clients ; i++) {
    *sd = client_socket[i].sock;

    if (*sd > 0)
    FD_SET(*sd , my_set);

    if (*sd > *max_sd)
    *max_sd = *sd;
  }

}

void			handle_incoming_connexion(int master_socket, int new_socket, t_client *client_socket, char *buffer, struct sockaddr_in address, socklen_t addrlen) {
  int			i;
  int			max_clients;

  max_clients = 30;
  if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    my_printf("ERROR during 'accept' !\n");
    exit(EXIT_FAILURE);
  }

  my_printf("New connection , socket fd is %d , ip is : %s , port : %d \n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

  if( (int) send(new_socket, buffer, strlen(buffer), 0) != (int) strlen(buffer) )
  my_printf("ERROR during 'send' !\n");
  send(new_socket , "Quel est ton nom ?\n> " , 21, 0 );

  /* puts("Welcome message sent successfully"); */

  for (i = 0; i < max_clients; i++) {
    if( client_socket[i].sock == 0 ) {
      client_socket[i].sock = new_socket;
      my_printf("Adding to list of sockets as %d\n" , i);

      break;
    }
  }
}

void parse_message(char *message) {
  my_printf("parsing : %s", message);
}

void			handle_socket_set_IO(fd_set *my_set, t_client *client_socket, char *buffer, int *sd) {
  int			i;
  int			max_clients;
  int			valread;
  int			buflen;
  char			*sender;
  int			reciever;

  max_clients = 30;
  for (i = 0; i < max_clients; i++) {
    *sd = client_socket[i].sock;

    if (FD_ISSET( *sd , my_set)) {
      /* Check if it was for closing , and also read the incoming message */
      if ((valread = read( *sd , buffer, 1024)) == 0) {
        my_printf("Client %i disconnected !\n", *sd);

        close(*sd);
        client_socket[i].sock = 0;
      } else if (strlen(buffer) == 0) {
        my_printf("-------------------------\n");
      } else {
        buffer[valread] = '\0';
        my_printf("MESSAGE RECIEVED[%i] (%s): %s\n", client_socket[i].message_count ,client_socket[i].name, buffer);
        if (client_socket[i].message_count == 0) {
	  buflen = my_strlen(buffer);
          client_socket[i].name = malloc(sizeof(char) * BUFFER_SIZE);
	  my_strcpy(client_socket[i].name, buffer);
	  client_socket[i].name[buflen - 1] = '\0';
        }
        else if (client_socket[i].message_count == 1) {
          /* send(client_socket[i].sock , "bonjour" , 6 , 0 ); */
        }
      }
      sender = malloc(sizeof(char) * BUFFER_SIZE);
      my_strcpy(sender, client_socket[i].name);
      client_socket[i].message_count++;
      if (buffer[0] == '@') { /*message perso*/
	reciever = get_reciever(buffer);
	send_message(sender, reciever, buffer);
      } else
	broadcast_message(sender, client_socket, buffer);
      memset(buffer, 0, my_strlen(buffer));
    }
  }
}

void                    broadcast_message( char *sender, t_client *client_socket, char *buffer) {
  int			i;
  int			sd;
  int			max_clients;
  int                   ret_send;

  max_clients = 30;
  for (i = 0; i < max_clients; i++) {
    sd = client_socket[i].sock;
    if (sd != 0 && client_socket[i].message_count > 1) {
      my_printf("MESSAGE SENT TO client %i: %s\n", sd, buffer);


      char *str =  (my_strcmp(sender, client_socket[i].name) != 0 )
	? strconcat(6, BLU, "[", sender, "] \t: ", NRM, buffer)
	: strconcat(6, WHT, "[", "YOU", "] \t: ", NRM, buffer);

      my_printf("STR : %s\n", str);
      if ( (int)(ret_send = send(sd , str , strlen(str) , 0 )) != (int) strlen(str)) {
        perror("error send()");
      }
    }
  }
}


char			*strconcat(int num_args, ...) {
  int			strsize;
  va_list	        ap;
  int			i;
  char			*res;

  strsize = 0;
  va_start(ap, num_args);
  for (i = 0; i < num_args; i++)
    strsize += strlen(va_arg(ap, char*));

  res = malloc(strsize+1);
  strsize = 0;
  va_start(ap, num_args);
  for (i = 0; i < num_args; i++) {
    char *s = va_arg(ap, char*);
    strcpy(res+strsize, s);
    strsize += strlen(s);
  }
  va_end(ap);
  res[strsize] = '\0';

  return res;
}
