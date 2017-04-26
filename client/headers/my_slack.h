#ifndef                 _MY_SLACK_
# define                _MY_SLACK_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define UNUSED(x) (void)(x)

typedef struct s_sockaddr_in {
    short            sin_family;
    unsigned short   sin_port;
    struct in_addr   sin_addr;
    char             sin_zero[8];
} t_sockaddr_in;

typedef struct s_in_addr {
    unsigned long s_addr;
} t_in_addr;

typedef struct s_sockaddr {
    unsigned short    sa_family;
    char              sa_data[14];
} t_sockaddr;

#endif                   /* !_MY_SLACK_ */
