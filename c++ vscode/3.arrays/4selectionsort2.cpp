#include <iostream>
using namespace std;


int main(){
    int arr[5] = {2,4,1,7,3};
    
    for(int i=0;i<4;i++){
        int min = arr[i];
        int p;
        for(int j=i+1;j<5;j++){
          if(arr[j]<min){
              min = arr[j];
              p = j;
          }
        }   
    swap(arr[p],arr[i]);  
    }
  
  for(int i=0;i<5;i++){
      cout<< arr[i]<<" ";
       }
    
}