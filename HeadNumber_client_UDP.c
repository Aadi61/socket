#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    int csd, cport, len, num;
    char sendmsg[100], recvmsg[100];
    struct sockaddr_in servaddr;

    printf("Enter the port:\n");
    scanf("%d", &cport);
    printf("%d\n", cport);

    csd = socket(AF_INET, SOCK_DGRAM, 0);

    if (csd < 0) {
        printf("Can't create\n");
    } else {
        printf("Socket is created \n");
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);

    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);

    sendto(csd, &n, sizeof(n), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

    int arr[n];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sendto(csd, &arr, sizeof(arr), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

    return 0;
}
