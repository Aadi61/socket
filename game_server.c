#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

int is_anagram(char a[], char b[]) { 

  int i = 0;
  int freq_a[26] = {0};
  int freq_b[26] = {0};
  
  for (i = 0; i<4; i++) {
    freq_a[a[i] - 97]++;
    freq_b[b[i] - 97]++;
  }
   for (i = 0; i < 26; i++) {
    if (freq_a[i] != freq_b[i]) {
      return 0;
    }
  }

  return 1;
}

int main(){
    int sd,sd2,nsd,clilen,sport,len;
    int port, num;
    time_t ticks;
    char sendmsg[100],rcvmsg[100],rcvmsg2[100];
    struct sockaddr_in servaddr,cliaddr;

    printf("Enter the server port:\n");
    scanf("%d", &sport);
    printf("%d", sport);

    sd = socket(AF_INET, SOCK_STREAM,0);
    if(sd<0)
        printf("Can't Create \n");
    else
        printf("Socket is created \n");

    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(sport);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    sd2 = bind(sd,(struct sockaddr*)&servaddr, sizeof(servaddr));
    if(sd2<0)
        printf("Can't bind \n");
    else
        printf("Binded \n");

    listen(sd,5);

    clilen = sizeof(cliaddr);
    
    nsd = accept(sd,(struct sockaddr *)&cliaddr,&clilen);
    
    if(nsd<0)
        printf("Cant accept\n");
    else
        printf("Binded\n");
     int n=0;
    recv(nsd,&rcvmsg,100,0);
    printf("Received st1 %s\n",rcvmsg);
    recv(nsd,&rcvmsg2,100,0);
    printf("Received st2 %s\n",rcvmsg2);
    if(is_anagram(rcvmsg,rcvmsg2)){
     printf("Anagram");
}
    else{
printf("Not anagram");
}
  //For diagonal elements
   int sum = 0;
int flag=0;
    int arr[3][3];
     int column,row;
      column=row=0;
     recv(nsd,&arr,sizeof(arr),0);
   for (row = 0; row < 3; row++) {
      for (column = 0; column < 3; column++) {
         if (row == column)
            sum = sum + arr[row][column];
      }
   }
 
   //For Rows
   for (row = 0; row < 3; row++) {
      int sum1 = 0;
      for (column = 0; column < 3; column++) {
         sum1 = sum1 + arr[row][column];
      }
      if (sum == sum1)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   //For Columns
   for (row = 0; row < 3; row++) {
      int sum2 = 0;
      for (column = 0; column < 3; column++) {
         sum2 = sum2 + arr[column][row];
      }
      if (sum == sum2)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }
 
   if (flag == 1)
      printf("\nMagic square");
   else
      printf("\nNo Magic square");
}

