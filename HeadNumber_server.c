#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

int main(){
    int sd,sd2,nsd,clilen,sport,len;
    int port, num;
    time_t ticks;
    char sendmsg[100],rcvmsg[100];
    struct sockaddr_in servaddr,cliaddr;

    printf("Enter the server port:\n");
    scanf("%d", &sport);
    printf("%d", sport);

    sd = socket(AF_INET, SOCK_STREAM,0);
    if(sd<0)
        printf("Can't Create \n");
    else
        printf("Socket is created \n");

    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(sport);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    sd2 = bind(sd,(struct sockaddr*)&servaddr, sizeof(servaddr));
    if(sd2<0)
        printf("Can't bind \n");
    else
        printf("Binded \n");

    listen(sd,5);

    clilen = sizeof(cliaddr);
    
    nsd = accept(sd,(struct sockaddr *)&cliaddr,&clilen);
    if(nsd<0)
        printf("Cant accept\n");
    else
        printf("Binded\n");
    int n;
    recv(nsd,&n,sizeof(n),0);
    int arr[n];
    recv(nsd,&arr,sizeof(arr),0);
    for(int i=1; i<n-1; i++) {
     if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
     printf("%d\n",arr[i]);
       }
    }
