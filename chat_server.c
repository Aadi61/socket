#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

int main(){
    int sd, sport;
    struct sockaddr_in servaddr, cliaddr;
    char recvmsg[150], sendmsg[150]; // Increased buffer size to accommodate timestamp
    
    printf("Enter server port: ");
    scanf("%d", &sport);
    getchar();
    
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd < 0){
        printf("Socket can't be created\n");
    } else {
        printf("Socket created successfully\n");
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(sport);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int sd2 = bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(sd2 < 0) {
        printf("Can't bind\n");
    } else {
        printf("Binded successfully\n");
    }
    
    listen(sd, 5);
    int clilen = sizeof(cliaddr);
    int s = accept(sd, (struct sockaddr*)&cliaddr, &clilen);
    if(s < 0){
        printf("Not accepted\n");
    } else {
        printf("Accepted successfully\n");
    }
    
    while(1){
        recv(s, recvmsg, 150, 0);
        printf("Message received from client: %s\n", recvmsg);
        
        printf("Enter message to send to client: ");
        fgets(sendmsg + 25, 100, stdin);
        
        time_t current_time = time(NULL);
        snprintf(sendmsg, sizeof(sendmsg), "%s: %s", ctime(&current_time), sendmsg + 25);
        
        send(s, sendmsg, strlen(sendmsg), 0);
    }
    
    return 0;
}
