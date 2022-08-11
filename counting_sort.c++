#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[0],int size){
    for (int  i = 0; i < size; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int size;
    cin>>size;


    int array[size];
    for (int  i = 0; i < size; i++)
    {
        cin>>array[i];
    }

cout<<"Before Sort "<<endl;
printArray(array,size);

    //step 1 Finding Max


    int max=INT_MIN;
    for (int  i = 0; i < size; i++)
    {
        if(array[i]>max){
            max=array[i];
        }
    }
    
    //step 2 initalization of count array
    int count[max+1]={0};

    // initialaizing 0

    // for (int i = 0; i <=max; i++)
    // {
    //     count[i]=0;
    // }
    
    

    ///step 3 Frequency calculation

    for (int  i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    
    // step 4  prefix sum;

    for (int  i = 1; i <=max; i++)
    {
        count[i] += count[i-1];
    }

    //step 5 backward traversal of array;
    int final[size]={0};
    for (int j=1, i =size-1; i >=0; j++,i--)
    {
        count[array[i]]--;
        int k=count[array[i]];
        final[k]=array[i];
        cout<<"Steps:"<<j<<endl<<"\t";
        printArray(final,size);
        cout<<endl;

    }
    
    // cout<<"After Sort "<<endl;
}