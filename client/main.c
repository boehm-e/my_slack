#include "./headers/libmy.h"
#include "./headers/my_slack.h"


int main(/*int argc , char *argv[]*/)
{
    int socket_desc;
    t_sockaddr_in server;
    char *message , server_reply[2000];

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8080 );

    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected\n");

    while (1) {
        message = readline();
        my_printf("=======\n%s========\n", message);
        if( send(socket_desc , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        puts("Data Send\n");

        if( recv(socket_desc, server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
        }
        puts("Reply received\n");
        puts(server_reply);
        free(message);
    }

    return 0;
}
