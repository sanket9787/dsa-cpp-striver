#include<iostream>
using namespace std;
#include<vector>

// find thev all subsets inside array whose sum is divisible by a number k , k =3
// eg. arr = {1,2,3} k =3  , subsets will be -> (1,2),{1,2,3},{3}

void subsets(int arr[],vector<int> &ds,int n,int i,int k){
    if(i == n){
        int sum = 0;
        for(auto it:ds){
            sum = sum + it;
        }
        if(sum % k == 0){
            for(auto it:ds){
                cout << it << " ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    subsets(arr,ds,n,i+1,k);
    ds.pop_back();
    
    subsets(arr,ds,n,i+1,k);
}
// or

void subsets2(int arr[],vector<int> &ds,int n,int i,int k,int sum){
    if(i == n){
       if(sum % k == 0){
           for(auto it: ds){
               cout << it<<" ";
           }
           cout << endl;
       }
        return;
    }

    ds.push_back(arr[i]);
    sum = sum + arr[i];
    subsets2(arr,ds,n,i+1,k,sum);
    ds.pop_back();
    sum = sum-arr[i];
    
    subsets2(arr,ds,n,i+1,k,sum);
}

int main(){
    int arr[3] = {1,2,3};
    vector<int> ds;
    int n = 3;
    int i =0;
    int k =3;
    int sum = 0;
    subsets2(arr,ds,n,i,k,sum);
}

