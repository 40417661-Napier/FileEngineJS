#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include "words.h"
#include "myfunctions.h"

int main()
{
  int welcomeSocket, newSocket, portNum, clientLen, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

  portNum = 7891;

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(portNum);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

  if (listen(welcomeSocket, 5) == 0)
    printf("Listening\n");
  else
    printf("Error\n");

  addr_size = sizeof serverStorage;

  //Own variables
  int i;

  /*loop to keep accepting new connections*/
  while (1)
  {
    newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);
    while (1)
    {
      nBytes = 1;
      /*loop while connection is live*/
      recv(newSocket, buffer, 1024, 0);
      removeNewLine(buffer);
      char toFind[1024];
      strcpy(toFind, buffer);

      //traverse, translate and store in buffer
      int j, found = 0;
      for (j = 0; j < 20; j++)
      {
        strcpy(buffer, eng[j]);
        if (strcmp(buffer, toFind) == 0)
        {
          found = 1;
          break;
        }
      }
      if (found)
      {
        strcpy(buffer, esp[j]);
        printf("Found");
        nBytes = strlen(buffer) + 1;
        send(newSocket, buffer, nBytes, 0);
      }
      else
      {
        send(newSocket, "Not found", 10, 0);
      }
    }
  }
  return 0;
}