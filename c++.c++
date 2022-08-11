

#include<bits/stdc++.h>
using namespace std;

void deletion(int arr[],int size, int pos){
    for (int  i = pos+1; i < size; i++)
    {
        arr[i-1]=arr[i];
    }
    size--;
    

};
int main(){
    int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    };


int loop=0;
int my=n;
    for (int  i = 0; i < n; i++)
    {
       for (int  x = i+1; x < n-1; x++)
       {
        if(arr[i]==arr[x]){
            
            int pos=x;
            my--;
            // cout<<arr[pos]<<" "<<arr[i]<<" "<<i<<" "<<x<<endl;
            if(x!=i){
            deletion(arr,my,pos);
            loop++;
            n--;

            }
        }
       }
       
    }

    //printing
int ans=n-loop;
    for (int i = 0; i < ans; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
}