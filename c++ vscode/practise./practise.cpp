#include <iostream>
using namespace std;
#include <vector>







int main(){
	// Write your code here.
    int arr[] = {1, 2 ,4 ,5 ,6, 6, 6 };
    int n =7;
    int max,min;
    for(int i =0; i < n-1 ;i++){
       if(arr[i]<arr[i+1]){
         max =  arr[i+1] ;
       }
        else
        {
            max = arr[i];
        }
      
    }
    for(int i = 0; i< n-1; i++){
         if(min > arr[i+1]){
           min = arr[i+1];
           cout << min << endl;
       } 
        else{
            min = arr[i];
         cout << min << endl;
        }
    }
    cout << min <<" " << max;
    
    
}










    
   

