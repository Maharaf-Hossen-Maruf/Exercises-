#include<bits/stdc++.h>
using namespace std;

//printing Array
void print_array(int arr[],int size){

    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    } 
    cout<<endl;

}

int main(){
    int size;
    cin>>size;

    int arr[size];
    //inputing arr
    for (int  i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
for (int  i = 1; i < size; i++)
{
    int key=arr[i];
    int j=i-1;
    cout<<i<<endl<<"";
    while (arr[j]>key && j>=0)
    {
       arr[j+1] = arr[j];
    print_array(arr,size);
       j--;
    }
    arr[j+1]=key;
    print_array(arr,size);
    
}

// cout<<"After Sort : "<<endl;
cout<<endl;
    
}