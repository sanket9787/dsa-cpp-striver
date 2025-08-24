#include<iostream>
using namespace std;

// find the number of subsets whose sum is equals to k;
 
int function(int arr[],int k,int sum,int ind){
    int l = 0;
    int r = 0;
    if(ind == 5){
        if(sum == k) return 1;
        else return 0;
    }

    sum = sum + arr[ind];
     l = function(arr,k,sum,ind+1);
    sum = sum - arr[ind];

    r = function(arr,k,sum,ind+1);
   return l+r;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int k = 1;
    int sum = 0;
    int ind =0;
    
   cout << function(arr,k,sum,ind);
}
