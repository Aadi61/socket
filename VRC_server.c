#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

int main(){
    int sd, sport;
    struct sockaddr_in servaddr, cliaddr;
    char recvmsg[1024];
    char buffer[1024] = {0};
    
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
    

    recv(s, recvmsg, 1024, 0);
    printf("Message received from client: %s\n", recvmsg);

    strcpy(buffer, recvmsg);
    int num = 0;
    for(int i = 0; i<1024; i++){
        // printf("%c ", buffer[i]);
        if(buffer[i] == '1'){
            num++;
        }
    }

    if(num%2 == 0){
        printf("Message Correct\n");
    }
    else{
        printf("Error\n");
    }
    
    return 0;
}
