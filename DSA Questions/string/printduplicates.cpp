#include <iostream>
using namespace std;
#include <map>
#include <string> 

void printDups(string str){
      map < char, int > count;
      for(int i =0 ; i< str.length(); i++){
          count [str[i]++];
      }
      for ( auto it : count){
          
      }

}

int main (){
    string str = "test string";
    printDups(str);
    return 0;
}


