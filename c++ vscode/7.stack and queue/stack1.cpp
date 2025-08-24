#include<iostream>
#include<stack>
using namespace std;

class Stack{
    
    public : 
    int *arr;
    int top; 
    int size;

    Stack( int data){
         this -> size = data;
         arr = new int[size];
         top = -1;
    }

    void push(int element){
       if(size - top > 1){
           top++;
           arr[top] = element;
       }
       else{
           cout  << "stack overflow"<< endl;
       }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    }
    int peek () {
        if(top >= 0){
            return arr[top];
        }
        else{
            cout << "stack is empty"<<endl;
            return -1;
        }

    }
    bool isempty (){
        if(top == -1){
            return true;
        }
        else {
            return false;
        }
    }
    void print(){
        int a = sizeof(arr)/ sizeof(arr[0]);
        for(int i =0 ;i< a ; i++){
            cout << arr[i]<< " ";
        }
        cout << endl;
    }

};

int main(){

 Stack st(5);
 st.push(3);
 st.push(5);
 st.push(6);

 cout << st.peek() <<endl;



st.push(7);
st.push(8);





}