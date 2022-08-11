// #include
#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;

    for (int  x = 0; x < n; x++)
    {
        int size;
        cin>>size;

        int arr[size];
        for (int  i = 0; i < size; i++)
        {
            cin>>arr[i];
        }

        //finding max number 
        int max=arr[0];
        for (int  i = 0; i < size; i++)
        {
           if (arr[i]>max){
            max=arr[i];
           }
           
           
        }
        
        int fre[max+1]={0};

        for (int  i = 0; i < size; i++)
        {
               int value=arr[i];
               fre[value]++;
        }
        int max_val=fre[0];
        for (int  i = 0; i <= max; i++)
        {
           if(fre[i]>max_val){
            max_val=fre[i];
           }
        }
        // cout<<"MAx val is "<<max_val<<endl;
        // for (int  i = 0; i <= max; i++)
        // {
        //     cout<<"ARr is -> "<<fre[i]<<endl;
        // }
        
        // cout<<"Four is" <<fre[4]<<endl;
int ans=size-max_val;
cout<<ans<<endl;

}

}