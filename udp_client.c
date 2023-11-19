#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

int main(){
    int sd, cport;
    struct sockaddr_in servaddr;

    printf("Enter client port: ");
    scanf("%d", &cport);

    sd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sd < 0){
        printf("Can't create socket");
    }
    else{
        printf("Socket created");
    }

    //memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);

    // UDP doesn't have a "connect" method like TCP
    // You can directly send data using `sendto` without connection establishment

    // Example: Sending a message to the server
    char message[100] = "This is it";
    int len, n;
    int servlen = sizeof(servaddr);
    len = sizeof(servaddr);
    n = sendto(sd, message, strlen(message),
               0, ( struct sockaddr *)&servaddr,
               servlen);
    if (n < 0) {
        printf("Error in sending message to the server");
    } else {
        printf("Message sent to the server  %s",n);
    }

   // close(sd);
    return 0;
}
