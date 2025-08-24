#include<iostream>
using namespace std;

bool search(int arr[],int size,int key){
    if(size == 0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
      return search(arr+1,size-1,key);
    }
   
}


int main(){
    int arr[5] = {2,4,5,7,8};
    int size = 5;
    int key = 9;
   bool ifpresent =  search(arr,size,key);

   if(ifpresent){
       cout << "present" ;
   }
   else{
       cout << "Not present";
   }
}