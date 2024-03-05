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

sd = socket(AF_INET, SOCK_STREAM, 0);

if(sd<0){
printf("Cant create socket");
}
else{
printf("Socket created successfully");
}

servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(sport);//host to network short data type->providing the port number(must be greater than 1065 cos before that all ports are pre defined)
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//host to network long data type-providing the IP address as argument

sd2= bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));//defines the socket address
if(sd2<0){
printf("Cant bind");
}
else{
printf("Binded successfullyz");
}

listen(sd,5);//2nd argument is queue limit i.e, how many number of request it can accept
clilen = sizeof(cliaddr);

int nsd = accept(sd, (struct sockaddr*)&cliaddr,&clilen);

if(nsd<0){
printf("Accepted successfully");
}
else{
printf("Cant accept");
}
}


