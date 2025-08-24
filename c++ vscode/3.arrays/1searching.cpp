
#include <iostream>
using namespace std;


int search(int arr[],int n, int key){

    for(int i=0;i<n;i++ )
    {
        if(key==arr[i]){
         return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[i]=a;
    }

  int key;
  cin>>key;
  cout<< search(arr,n,key)<<endl;
  

}
