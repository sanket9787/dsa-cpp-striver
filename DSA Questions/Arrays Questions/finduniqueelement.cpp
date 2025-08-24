
 #include <iostream>
 #include <bits/stdc++.h>
using namespace std; 
  
int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        while(j<n){
            cout<<j<<endl;
            cout<<i<<endl;
            if(nums[i]!= nums[j]){
                
                i++;
                nums[i] = nums[j];
                j++;
            }else j++;
        }
        cout<<j<<endl;
        cout<<i<<endl
        if( n == 1){
            return 1;
        }else  return i;
       
    }

int main(){
   vector<int> nums = [1,1,2];
   int k = removeDuplicates(nums);
   cout<<k<< endl;
}