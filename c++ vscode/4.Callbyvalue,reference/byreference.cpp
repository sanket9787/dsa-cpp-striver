#include <iostream>
using namespace std;

// 2 3 4 2 5

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int main(){
  
  int a,b;
  
//   int *aptr=&a;
//   int *bptr=&b;
  
  cin>>a>>b;
  swap(&a,&b);  //another method to send address to a function
 cout<<a<<" "<<b<<endl;  


    
   } 
  

