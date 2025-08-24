#include<bits/stdc++.h>
using namespace std;

int maxSubarraySub(int arr[], int n){
    
    int max = INT_MIN;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum+arr[i];
        if(sum > max){
            max = sum;
        }
        if(sum < 0) sum = 0;
    }
    return max;
}

int main(){
    vector<int> ans;
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    

    int n = sizeof(arr) / sizeof(arr[0]);
    int anss = maxSubarraySub(arr, n);
    
    cout<< anss;
}