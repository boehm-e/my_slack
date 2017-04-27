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
  char		name[BUFFER_SIZE];
} t_client;


int		init(int *client_socket, struct sockaddr_in *_address, int *_addrlen);
void		reinit_socket(fd_set *readfds,
			      int master_socket,
			      int *client_socket,
			      int *sd,
			      int *max_sd);

void		handle_incoming_connexion(int master_socket,
					  int new_socket,
					  int *client_socket,
					  struct sockaddr_in address,
					  socklen_t addrlen);

void		handle_socket_set_IO(fd_set *readfds,
				     int *client_socket,
				     int *sd,
				     struct sockaddr_in address,
				     socklen_t addrlen);

#endif                   /* !_MY_SLACK_ */
