#include <iostream>
#include <map>
using namespace std;


/* 
given N strings, print unique strings in 
lexiographical order with their frequency
N <= 10^5;
|s| = 100; length of string can be..
*/

int main(){
   map<string,int> m;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       string s;
       cin>> s;
    //    m[s]=m[s]+1;
    m[s]++; 
  }
  for(auto pr: m){
      cout<< pr.first << " " << pr.second;
  }
}

/* input -> 
5
abc
def
abc
ghg
jkl
ghg
ghg
abc
 
output ->
abc 3
def 1
ghj 3
jkl 1

*/
