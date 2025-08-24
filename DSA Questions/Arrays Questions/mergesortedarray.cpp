#include <iostream>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m,int arr3[])
{
    int i=0,j=0,k=0;
  while(i<n && j<m){
      if(arr1[i]<arr2[j]){
          arr3[k]=arr1[i];
          k++;
          i++;
         }
      else if(arr1[i]>arr2[j]){
          arr3[k]=arr2[j];
          k++;
          j++;
      }
  }


  while(i<n)
  {
    arr3[k]=arr1[i];
    i++;
    k++;
  }
   while(j<m)
  {
    arr3[k]=arr2[i];
    j++;
    k++;
  }

}

int main()
{
   


  int arr1[4]={1,3,4,7};
    int arr2[3]={2,5,6};

    int arr3[7];

    merge(arr1,4,arr2,3,arr3);
    
    for(int i=0;i<7;i++)
    {
       cout<<arr3[i]<<" ";
    }

    
}