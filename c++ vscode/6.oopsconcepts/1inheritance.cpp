#include <iostream>
using namespace std;

//protected : can be accessed only within class or derived class or subclass 
class cart{
    private :
    int length;

    public :
    int height;
    int weight;

    

    int getheight(int data)
    {
        return this->height = data;

    }
    void setweithg(int data){
        this-> weight = data;

    }

};
class male: public cart{
    public : 
    int age;

    void sleep(){
       cout << "male sleeping"<<endl;
    }
};

int main(){

 cart ob1;
 male ob2;

 cout<< ob1.height <<endl;
 cout << ob2.height <<endl;  // different value of height for class inherited from base class

 

return 0;


 


}