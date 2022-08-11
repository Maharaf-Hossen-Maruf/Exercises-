#include<bits/stdc++.h>
using namespace std;

//printing array
void print_arr(int arr[],int size){
for (int  i = 0; i < size; i++)
{
    cout<<arr[i]<<" ";
}

// cout<<endl;

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



// cout<<"Before Sort : "<<endl;
// print_arr(array,size);


for (int  i = 1; i < size; i++)
{
    cout<<i<<"st iteration: "<<endl;
    for (int  j = 0; j < size-1; j++)
    {
        cout<<"\t\t"<<j+1<<"st step:";
        print_arr(array,size);
        cout<<"->";



        if(array[j]>array[j+1]){
            int temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
        print_arr(array,size);
        cout<<endl;
    }


    
}
    // cout<<"After Sort : "<<endl;
    // print_arr(array,size);


}