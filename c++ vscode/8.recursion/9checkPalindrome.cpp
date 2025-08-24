#include<iostream>
using namespace std;

bool checkpalindrome(string &str,int s,int e){
    if(s==e && str[s] == str[e]){
        return true;
    }
    if(str[s] == str[e]){
        return checkpalindrome(str,s+1,e-1);
    }
    else{
        return false;
    }
}
int main(){
    string str = "laskgjo";
    int s = 0;
    int e= str.length()-1;
   bool palindrome =  checkpalindrome(str,s,e);
   if(palindrome){
       cout<< "Given string is palindrome";
   }
   else{
       cout << "Not palindrome";
   }
}