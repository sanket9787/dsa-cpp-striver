#include <iostream>
using namespace std;
#include <vector>

// 2 3 4 5 6
//Given an array, rotate the array to the right by k steps, where k is non-negative.


int main(){
    vector <int> nums = {1,2,3,4,5};
    int k=3;

     vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }

     nums=temp;
    for(int i=0;i<nums.size();i++)
{
    cout << nums[i]<<" ";
} 

}
