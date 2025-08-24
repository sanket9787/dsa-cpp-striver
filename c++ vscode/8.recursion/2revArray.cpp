#include<iostream>
#include<stack>
using namespace std;

void swap(int a,int b){
    int c ;
    c = a;
    a = b;
    b = c;
}
int reverse(int start,int end,int arr[]){

    if(start >= end){
        return start;
    }
    swap(arr[start],arr[end]);
    reverse(start+1,end-1,arr);
}

int main(){
   
   int arr[5] = {5,4,3,2,1};
   int start = 0;
   int end = 4;
   reverse(start,end,arr);
   for(int i=0;i<5;i++){
    cout << arr[i]<< " ";
   }
}
