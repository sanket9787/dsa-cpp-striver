#include<iostream>
#include<stack>
using namespace std;

void saydigit(int a,string arr[]){

    if(a==0){
        return ;
    }
    int digit = a%10;
    a = a/10;
    
    saydigit(a,arr);
    cout << arr[digit]<<" ";
}



int main(){
    string arr[10] = {
        "zer0","one","two","three","four","five","six","seven","eight","nine"
    };

    int a = 41234;
    saydigit(a,arr);
}