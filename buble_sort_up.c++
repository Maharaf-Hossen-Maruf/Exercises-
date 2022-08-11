#include<bits/stdc++.h>
using namespace std;

//printing array
void print_arr(int arr[],int size){
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

//input array
for (int  i = 0; i < size; i++)
{
    cin>>array[i];
}



cout<<"Before Sort : "<<endl;
print_arr(array,size);


for (int  i = 1; i < size; i++)
{
    int flag=0;
   cout<<"iteration no : "<<i<<endl;
    for (int  j = 0; j < size-i; j++)
    {
       
        if(array[j]>array[j+1]){
            int temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            flag=1;
        }

         print_arr(array,size);

       
    }

cout<<endl;
    if(flag==0) break;
}
    cout<<"After Sort : "<<endl;
    print_arr(array,size);
    cout<<endl;


}