#ifndef                 _MY_SLACK_
# define                _MY_SLACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#define TRUE   1
#define FALSE  0
#define PORT 8080
#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

typedef struct	s_client {
  int		sock;
  char		*name;
  int		message_count;
  char		*private_key;
  char		*public_key;
} t_client;



int		init(t_client *client_socket,
		     struct sockaddr_in *_address,
		     int *_addrlen);

void		reinit_socket(fd_set *my_set,
			      int master_socket,
			      t_client *client_socket,
			      int *sd,
			      int *max_sd);

void		handle_incoming_connexion(int master_socket,
					  int new_socket,
					  t_client *client_socket,
                                          char *buffer,
					  struct sockaddr_in address,
					  socklen_t addrlen);

void		handle_socket_set_IO(fd_set *my_set,
				     t_client *client_socket,
                                     char *buffer,
				     int *sd);

void            broadcast_message(t_client *client_socket,
                                  char *buffer);


#endif                   /* !_MY_SLACK_ */
