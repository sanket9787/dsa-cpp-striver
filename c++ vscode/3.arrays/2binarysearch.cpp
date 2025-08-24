
#include <iostream>
using namespace std;

// 2 3 4 5 6

int binsearch(int arr[],int n, int key){
    
    int s=0;
    int e=n;
    while(s<=n){
        int mid=(s+e)/2;
        if(key==mid)
        {
            return mid;
        }
        else if(key<arr[mid]){
           e=mid-1;

          }
       else{
           s=mid+1;
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
  cout<< binsearch(arr,n,key)<<endl;
  return 0;
  

}

// complexity of linear search = o(n)
// complexity of binary search= o(logn) ,base 2 

// t(n)=k+t(n/2)
//    t(n/2)=k+t(n/4)
//    .
//    .
//    t(1)=k 

//    adding all
//    t(n)=k+ k+ k+....
//    n is aproaching to 1 
//    n--> n/2 -->n/4 ....1
//   that is  n/2^x = 1 taking log , logn=xlog2 , logn=x 

