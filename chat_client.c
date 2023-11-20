#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

int main(){
    int cd, cport;
    struct sockaddr_in servaddr;
    char recvmsg[150], sendmsg[150]; // Increased buffer size to accommodate timestamp
    
    printf("Enter client port: ");
    scanf("%d", &cport);
    getchar();
    
    cd = socket(AF_INET, SOCK_STREAM, 0);
    if(cd < 0){
        printf("Socket can't be created\n");
    } else {
        printf("Socket created successfully\n");
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(cport);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int cd2 = connect(cd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(cd2 < 0){
        printf("Can't connect\n");
    } else {
        printf("Connected successfully\n");
    }
    
    while(1){
        printf("Enter message to send to server: ");
        fgets(sendmsg + 25, 100, stdin);
        
        time_t current_time = time(NULL);
        snprintf(sendmsg, sizeof(sendmsg), "%s: %s", ctime(&current_time), sendmsg + 25);
        
        send(cd, sendmsg, strlen(sendmsg), 0);
        
        recv(cd, recvmsg, 150, 0);
        printf("Message received from server: %s\n", recvmsg);
    }
    
    return 0;
}
