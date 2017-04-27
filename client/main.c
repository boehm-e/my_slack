#include "./headers/libmy.h"
#include "./headers/my_slack.h"


int main(/*int argc , char *argv[]*/)
{
  int socket_desc;
  t_sockaddr_in server;
  char *message , server_reply[BUFFER_SIZE];

  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }

  server.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Erwan : 172.16.16.162 */
  server.sin_family = AF_INET;
  server.sin_port = htons( 8080 );

  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
    my_printf("connect error");
    return 1;
  }

  my_printf("Connected\n");

  while (1) {
  nomsg:
    message = readline();
    if (!message) {
      my_printf("/!\\ EMPTY MESSAGE /!\\  -- not sent\n");
      goto nomsg;
    }

    my_printf("SENDING MESSAGE : %s\n", message);
    if( send(socket_desc , message , my_strlen(message) , 0) < 0) {
      my_printf("Send failed");
      return 1;
    }

    memset(server_reply, 0, my_strlen(server_reply));

    if( recv(socket_desc, server_reply , BUFFER_SIZE , 0) < 0)
      my_printf("recv failed");

    my_printf("SERVER REPLY RECIEVED : %s\n", server_reply);
    free(message);
  }

  return 0;
}
