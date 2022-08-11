#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        // cout<<endl;
        int size,exp;
        cin>>size>>exp;
        int arr[size];
        for (int x = 0; x < size; x++)
        {
            cin>>arr[x];
        }

int m,end,min,arr_exp[exp];
            
        for (int x = 0; x < exp; x++)
        {
           cin>>m>>end;
                min=arr[m-1];

           for (int strt= m-1; strt < end; strt++)
           {
                if(arr[strt]<min){
                    min=arr[strt];
                }
           }
           arr_exp[x]=min;
        }
        cout<<"Case "<<i<<":"<<endl;
        for(int p=0;p<exp;p++){
          cout<<arr_exp[p]<<endl;

        }
        
    }
    

}