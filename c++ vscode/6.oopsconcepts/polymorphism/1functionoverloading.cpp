#include<iostream>
#include<stack>
using namespace std;

// this comes under compile time polymorphism
class overload{
    public :
    
    void func1(){
        cout << "function overloading";
    }
    void func1(int a){
        cout << "function overloaded";
    }
    int func1(int a){
        cout<< "different return type cannot overload function";
    }

};

int main(){
    overload ob1;
    ob1.func1();

}