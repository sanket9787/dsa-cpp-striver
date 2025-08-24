#include <iostream>
using namespace std;
#include <string> 

//    char lowercase( char s ){

//         if( s>= 'A' && s<='Z' ||  s>= '0' && s<='9' ){
//               return s ;
            
//         }
//         else{
//             char temp = s - 'A' + 'a';
//             return temp;
//         }
//     }
    
  
    
    int main () {
        string s = "A man, a plan, a canal: Panama";
        string str = "";
        for(int i = 0 ; i< s.length(); i++){
            if(s[i]>= 'a' && s[i]<='z' || s[i]>= 'A' && s[i]<='Z' || s[i]>= '0' && s[i]<='9'){
   
        str.push_back(s[i]);
            
            }}
        cout << "str =" << str << endl;
        
        // for ( int i = 0 ; i< str.length(); i++){
  
        //      str [ i ] = lowercase(str[i]);        
        
        // }
        
        transform(str.begin(),str.end(),str.begin(), ::tolower);
       
        cout << "lowercase = " << str << endl;

       string temp = str;
       int st= 0;
       int e = temp.length()-1;
       while( st<= e ){
            swap(temp[st],temp[e]);
       }
        cout<< temp << endl;
  
     return 0;
 
  
    }
    