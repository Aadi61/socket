#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

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
     int n=0;
    for(int i=0; i<10; i++) {
        recv(nsd, &num, sizeof(num), 0);
        if(isPrime(num)) {
            send(nsd, &num, sizeof(num), 0);
        }
        else{
        send(nsd,&n,sizeof(n),0);
       }
    }
}
