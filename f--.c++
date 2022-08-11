#include<bits/stdc++.h>
using namespace std;

void PrintArr(int arr[],int size){
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

for (int  i = 0; i < size; i++)
{
	cin>>arr[i];

}

PrintArr(arr,size);

for (int  i = 1; i < size; i++)
{
	int key=arr[i];
	int j=i-1;
	while (arr[j]>key && j>=0)
	{
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=key;
	
}

PrintArr(arr,size);

return 0 ;
}