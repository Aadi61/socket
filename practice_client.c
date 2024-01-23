#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

int main(){
int cd,cport;
struct sockaddr_in servaddr;

printf("Enter client port");
scanf("%d", &cport);

cd=socket(AF_INET, SOCK_STREAM, 0);

if(cd < 0){
printf("Cant create socket");
}
else{
printf("Socket created");
}

servaddr.sin_family= AF_INET;
servaddr.sin_addr.s_addr= htonl(INADDR_ANY);
servaddr.sin_port= htons(cport);

if(connect( cd, (struct sockaddr*)&servaddr, sizeof(servaddr) ) <0){//similar to bind
printf("Cant connect");
}
else{
printf("Connected");
}
}

