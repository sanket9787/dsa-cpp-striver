#include<iostream>
using namespace std;
int getsum(int *arr,int size){

  if(size==0){
    return 0;
  }
  if(size == 1){
      return arr[0];
  }
   
    int sum = arr[0]+getsum(arr+1,size-1);
    return sum;
}
int main(){
    int arr[5] = {
        3,5,7,8,9
    };

   int size = 5;
   int sum = getsum(arr,size);
   cout << sum <<endl;
}