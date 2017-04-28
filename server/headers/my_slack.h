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

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

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

void            broadcast_message(char *sender,
				  t_client *client_socket,
                                  char *buffer);

char		*strconcat(int num_args, ...);

#endif                   /* !_MY_SLACK_ */
