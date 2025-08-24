#include<iostream>
using namespace std;

int main(){

    int arr[7]= {6,8,9,8,7,15,2};
    int n=7;
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j<0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    } 
}