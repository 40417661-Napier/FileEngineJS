/****************** SERVER CODE ****************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  int welcomeSocket, newSocket;

  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(40000);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  if(bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0 ){
    printf("\nERROR on Binding");
  }

  if(listen(welcomeSocket,5) == 0){
    printf("Listening\n");
    /* CODE TO SEND FIXED MESSAGE HERE */
  }
  else{
    printf("Error\n");
  }

  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);


  if(newSocket<0){
    printf("Error on binding!\n");
    exit(0);
  }
  else{
    printf("Binding Success!\n");
  }
  
  printf("\nENDING SESSION");
  printf("\n");
  return 0;
}

