
#include<bits/stdc++.h>
using namespace std;

int main(){
string str;
cin>>str;


int len=str.length();
// cout<<len<<endl;
int a=0,z=0;
for (int i = 0; i < len; i++)
{
    if(str[i]=='A'){
        a=i+1;
        break;
    }
}

for (int j =len-1; j >=0 ; j--)
{
    if (str[j]=='Z')
    {
       z=j+1;
       break;
    }
    
}

int ans=(z-a)+1;
cout<<ans<<endl;



}