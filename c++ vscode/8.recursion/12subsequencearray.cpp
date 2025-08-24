#include<iostream>
using namespace std;
#include<vector>

// print all the subsets of the array for eg. arr[] = {1,2,3}
// subsets are {1},{2},{3},{1,2},{2,3},{1,3},{1,2,3},{}

void subsets(int arr[],vector<int> &ds,int n,int i){
    if(i == n){
        for(auto it:ds){
            cout << it<<" ";
        }
        cout<< endl;
        return;
    }
    ds.push_back(arr[i]);
    subsets(arr,ds,n,i+1);
    ds.pop_back();
    
    subsets(arr,ds,n,i+1);

}
int main(){
    int arr[3] = {1,2,3};
    vector<int> ds;
    int n = 3;
    int i =0;
    subsets(arr,ds,n,i);
}