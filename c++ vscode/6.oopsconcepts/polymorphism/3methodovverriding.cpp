#include<iostream>
#include<stack>
using namespace std;

// possible through inheritance only
//method of parent class and child class must have same name and parameters

class parent{
   public :
   void show(){
       cout<< "This is parent class"<<endl;
   }
   void app(){
       cout << "this is app";
   }
};
class subclass1 : public parent {
    public: 
    void show(){
        cout<< "This is subclass1"<<endl;
    }
};

class subclass2 : public parent {
    public :
    void show(){
        cout << "This is subclass2"<<endl;
    }
};

int main(){
    subclass1 ob1;
    subclass2 ob2;
    ob1.show();
    ob2.show();
}
