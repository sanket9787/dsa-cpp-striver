#include<iostream>
#include<string>
using namespace std;

int findlength(string str , char coder){

    int cnt = 0;
  for(int i = 0 ; i< str.length();i++){
      if( str[i] == coder ){
          cnt++;
      }

  }
  return cnt;
}
    



int main(){
  string string = "hello";
  char coder = 'l';
  
 cout<< findlength(string,coder)<<endl;



}