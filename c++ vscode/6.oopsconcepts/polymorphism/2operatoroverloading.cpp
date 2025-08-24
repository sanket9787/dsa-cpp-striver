
#include<iostream>
#include<stack>
using namespace std;

// this comes under compile time polymorphismb or static polymorphism

class opoverload{
    public : 
    int a;
    int b;

    
  
  void operator+ (opoverload obj){
    int  value1 = this->a;
    int value2 = obj.b;
    cout << value2-value1<< endl;
  }
  void operator ()(){
      cout << "overloaded" ;
  }

};

int main(){
    opoverload obj1,obj2;
    obj1.a= 4;
    obj2.b= 5;
    
     
    obj1 + obj2; // same as obj1.add(obj2)
    
 


    

    
   

    
}