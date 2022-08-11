#include<bits/stdc++.h>
using namespace std;

int bainarySearch(int arr[],int x,int lb,int ub){

if(lb<=ub){
    int mid=(lb+ub)/2;

    if(x==arr[mid]) return mid;

    else if(x>arr[mid]) bainarySearch(arr,x,mid+1,ub);
    else bainarySearch(arr,x,lb,mid-1);

}

else return -1;


}


int main(){
    int size;
    cin>>size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    int checkvalue;
    cout<<"Enter the number for search "<<endl;
    cin>>checkvalue;

    int  indexNumber;
    indexNumber = bainarySearch(arr,indexNumber,0,size-1);
    

    if(indexNumber != -1) {
        cout<<"Index No : "<< indexNumber << " " <<"Position No "<< indexNumber +1<<endl;
    }
    else{
        cout<<"Not Found";
    }


    return 0;
    
}