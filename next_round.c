#include<stdio.h>
#include<string.h>
int main(){

 char inp[15];
 scanf("%s",inp);

 char my[]="Hello,World!";
 int x=strlen(my);
 //printf("%d\n",x);
 int y=0;
 for(int i=0;i<x;i++){
    if(inp[i]== my[i]){
      y++;
    }

 }
 if(y==12){
    printf("AC");

 } else{
        printf("WA");
    }

}
