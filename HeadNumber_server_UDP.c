#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
int main(){
    int sd, sport, len;
    int port, num;
    time_t ticks;
    char sendmsg[100], rcvmsg[100];
    struct sockaddr_in servaddr, cliaddr;

    printf("Enter the server port:\n");
    scanf("%d", &sport);
    printf("%d\n", sport);

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sd<0)
        printf("Can't Create \n");
    else
        printf("Socket is created \n");

    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(sport);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Can't bind \n");
        return 0;
    }
    else
        printf("Binded \n");

    len = sizeof(cliaddr);
    
    int n;
    recvfrom(sd, &n, sizeof(n), 0, (struct sockaddr *)&cliaddr, &len);
    int arr[n];
    recvfrom(sd, arr, sizeof(arr), 0, (struct sockaddr *)&cliaddr, &len);
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}
