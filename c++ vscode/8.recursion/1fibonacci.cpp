#include<iostream>
#include<stack>
using namespace std;

int fibonacci(int n)
{
    if(n<=1){
        return n;
    }
    int ans1 = fibonacci(n-2);
    int ans2 = fibonacci(n-1);
    return ans1+ans2;
}

int main(){
    int n;
    cin>> n;
    int i=0;
  while(i<n){
      cout<< fibonacci(i);
      i++;
  }

}
// time complexity is 2^N ;
// oxilarry space complexity -> how much depth is there how many time function calling itself.
