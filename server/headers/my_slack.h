#ifndef                 _MY_SLACK_
# define                _MY_SLACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

typedef struct	s_client {
  int		sock;
  char		name[BUFFER_SIZE];
} t_client;


int	create_socket();
int	recieve_msg(int _socket, char *msg);

#endif                   /* !_MY_SLACK_ */
