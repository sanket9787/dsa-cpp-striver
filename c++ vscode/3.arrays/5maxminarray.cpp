#include <iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int array[n];

   for(int i=0;i<n;i++)
   {
      int input;
      cin>>input;
      array[i]=input;
   }
 
 int maxno;
 int minno;

 for(int i=0;i<n;i++)
 { 
    //  if(maxno>array[i]){
    //      maxno= array[i];
    //  }
 
     //  if(minno<array[i]){
    //      maxno= array[i];
    //  }
   // maxno=max(maxno,array[i]);
   // minno=min(minno,array[i]);
   sort(array,array+n);
   minno=array[0];
   maxno=array[n-1];

   }



 cout<<maxno<<endl;
 cout<<minno<<endl;




}
