#include <iostream>
using namespace std;

// selectin sort
// 7 8 3 4 2 1
int main()
{
   int n;
   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++)
   {
      int input;
      cin>>input;
      arr[i]=input;
   }


 for(int i=0;i<n;i++)
 {
     for(int j=i+1;j<n;j++)
     {
         if(arr[j]<arr[i])
         {
             int temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
         }
     }

 }

 for(int i=0;i<n;i++)
 {
     cout<<arr[i];
 }





}

