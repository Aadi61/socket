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

	for(int i=0; i<10; i++) {
   		printf("Enter number %d: ", i+1);
   		scanf("%d", &num);
   		send(csd, &num, sizeof(num), 0);
   		recv(csd, &num, sizeof(num), 0);
                if(num==0){
               continue;
              }
   		printf("Received prime number from server: %d\n", num);
	}
}

