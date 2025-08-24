#include <iostream>
using namespace std;
#include <vector>

    vector<int> duplicates(int arr[], int n) {
         
       
    vector<int> ans;
         
         int arr1[n];
         int count=0;
         
         for(int i=0;i<n;i++){
            arr1[arr[i] ]=count++;
         }
         
         for(int i=0;i<n;i++){
           if(arr1[i]>1)
            {
              ans.push_back(arr1[i]); 
            }
       
     }
     
       return ans;
  
}

int main(){
    int n=5;
    int arr[] = {2,3,1,2,3};

 cout<<  duplicates(arr,5);
 

   



    
 
}