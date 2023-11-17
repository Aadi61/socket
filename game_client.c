
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int csd,cport,len,num;
	char sendmsg[100],recvmsg[100],sendmsg2[100];
	struct sockaddr_in servaddr;
        int arr[3][3];
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

	printf("Enter string\n");
        for(int i=0;i<4;i++){
        scanf("%c",&sendmsg[i]);
}
        send(csd,&sendmsg,100,0);
       printf("Enter string 2");       

 for(int i=0;i<4;i++){
       scanf("%c",&sendmsg2[i]);
}
	send(csd,&sendmsg2,100,0);
       printf("Enter matrix\n");
       for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          scanf("%d",&arr[i][j]);
      }
      }
       send(csd,&arr,sizeof(arr),0);
}
 
