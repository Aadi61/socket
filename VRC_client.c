#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

int main(){
    int cd, cport;
    struct sockaddr_in servaddr;
    char binary_string[1024];
    char buffer[1024] = {0};

    printf("Enter binary digits: ");
    fgets(binary_string, sizeof(binary_string), stdin);
    binary_string[strcspn(binary_string, "\n")] = '\0'; // Remove newline character

    // Calculate number of 1s and add parity
    int num_ones = 0;
    for (int i = 0; i < strlen(binary_string); ++i) {
        if (binary_string[i] == '1') {
            num_ones++;
        }
    }
    int parity = num_ones % 2;
    
    // Copy binary digits to buffer
    strcpy(buffer, binary_string);
    
    // Add parity bit at the end
    if (parity) {
        strcat(buffer, "1");
    } else {
        strcat(buffer, "0");
    }
    
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
    send(cd, buffer, strlen(buffer), 0);

    
    return 0;
}
