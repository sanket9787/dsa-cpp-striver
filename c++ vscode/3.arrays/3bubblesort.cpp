#include <iostream>
using namespace std;

// bubble sort
// for i=0
//     8 4 2 1 = (0 1 2 3)
//                4 8 2 1                             if n elements in array no of iterations will be n-1 , if 4 elements loop will run for
//                4 2 8 1                             3 times
//                4 2 1 8   from j=0 to j=n-i, j=3
//               
//  for i=1
//      4 2 1 8 =  
//                2 4 1 8
//                2 1 4 8   from j=0 to j=2
//                         
// 
// for i=2
//     2 1 4 8 =
//                1 2 4 8
//                
                 
            
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


// int counter=0;
// while(counter<n-1){                
//    for(int i=0;i<n-counter-1;i++){

//        if(arr[i]>arr[i+1]){
//            int temp=arr[i];
//            arr[i]=arr[i+1];
//            arr[i+1]=temp;

//        }

//    }
//    counter++;

// }

for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
 

for(int i=0;i<n;i++)
{
   cout<<arr[i]<<" ";
}



}
