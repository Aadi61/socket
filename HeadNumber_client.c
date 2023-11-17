#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int csd,cport,len,num;
	char sendmsg[100],recvmsg[100];
	struct sockaddr_in servaddr;

	printf("Enter the port:\n");
	scanf("%d",&cport);
	printf("%d",cport);

	csd = socket(AF_INET,SOCK_STREAM,0);
	
	if(csd<0){
		printf("Cant create\n");
	}
	else{
		printf("Socket is created \n");
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(cport);

	if(connect(csd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){
		printf("Cant connect\n");
	}
	else{
		printf("Connected successfully\n");
	}
	int  n;
        printf("Enter size of array\n");
	scanf("%d",&n);
        send(csd,&n,sizeof(n),0);
	int arr[n];
        for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
	}
	send(csd, &arr,sizeof(arr),0);
}
