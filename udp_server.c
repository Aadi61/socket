#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

int main(){
int sd,sport,sd2;
struct sockaddr_in servaddr,cliaddr;
int clilen;
printf("Enter the server port");
scanf("%d", &sport);

sd = socket(AF_INET, SOCK_DGRAM, 0);

if(sd<0){
printf("Cant create socket");
}
else{
printf("Socket created successfully");
}

servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(sport);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

sd2= bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));
if(sd2<0){
printf("Cant bind");
}
else{
printf("Binded successfullyz");
}
//char msg[] ="Hello";
char msg[100];
clilen = sizeof(cliaddr);
int count = recvfrom(sd, msg, sizeof(msg), 0,(struct sockaddr*)&cliaddr, &clilen);
printf("Message received %s", msg);
}
