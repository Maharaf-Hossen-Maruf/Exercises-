#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){

  char s[101];
  char b[101];
  
  scanf("%s",&s);
  strcpy(b,s);
//   printf("%s",b);
  bool ans=false;
  bool ans2=false;

  for (int i = 0,j=1; s[j]!='\0'; j++,i++)
  {
    if(!(s[0]>='a' && s[0]<='z' && s[j]>='A' && s[j]<='Z' )){
        ans=true;
        continue;
       
    }
    if(!(s[i]>='A' && s[i]<='Z') ){
        ans2=true;
        
    }
  }
  

  if(ans){
    strlwr(s);
    s[0]=s[0]-32;
    printf("%s",s);
    return 0;

  }
   if(ans2){
    strlwr(s);
   printf("%s",s);
   return 0;
  }
  else{
    printf("%s",b);
  }
  
 
  
  
}