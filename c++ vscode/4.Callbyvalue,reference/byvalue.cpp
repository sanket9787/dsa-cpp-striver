#include <iostream>
using namespace std;

// 2 3 4 2 5

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}


int main(){
  
  int a,b;
  cin>>a>>b;
  swap(a,b);
 cout<<a<<" "<<b<<endl;  

//  here output will be same no swapping is happened becase this is called pass by value 
// when swap function calls in it creates its own local varables but when we print a,b in main function it will print original values of a,b

// so to avoid this we use pointers which is called as pass by reference
    
   } 
  

