#include<iostream>
using namespace std;

int countdistinctwaytoclimbstairs(int n){
    if(n < 0)return 0;
    if(n==0)return 1;

    int ans = countdistinctwaytoclimbstairs(n-1)+countdistinctwaytoclimbstairs(n-2);
    return ans;

}

int main(){
    //no of stairs int n = 5;
    // one can jump 1 step or two step at a time ,find total number of possible ways to climb the stairs?
    int n = 5;
  cout <<  countdistinctwaytoclimbstairs(n);

}


            
        