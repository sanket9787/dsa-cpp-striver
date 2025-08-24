#include <iostream>
using namespace std;

// You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an 
// integer ‘K’.
// Now, your task is to find the first and last occurrence of ‘K’ in ARR.


int firstoccurance(int arr[],int n,int k){
    int s=0,e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }

        else if( k > arr[mid] ){ //RIGHT ME JAO
            s=mid+1;
        }
        else if( k< arr[mid] ){  //LEFT ME JAO
            e=mid-1;
        }

       mid=s+(e-s)/2;
    }
return ans;

}

int lastocccurance(int arr[],int n,int k){
      int s=0,e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }

        else if( k > arr[mid] ){ //RIGHT ME JAO
            s=mid+1;
        }
        else if( k< arr[mid] ){  //LEFT ME JAO
            e=mid-1;
        }

       mid=s+(e-s)/2;
    }
return ans;
}



int main(){

    int arr[]={0,4,6,6,6,6,7,7,8};
    int k;


    
    cout<<"first occurance of element k is "<< firstoccurance(arr,9,6)<<endl;
     cout<<"last occurance of element k is "<< lastocccurance(arr,9,6)<<endl;
}