#include <iostream>
#include <map>
using namespace std;

// in map keys are unique and set in sorted order
int main(){
    map<int,string > m;
    m[1]= "abc";  // time comlexity for this one line => o(log(n)) ek value ko map me dalne ki time complexity
    m[5]= "cdc"; 
    m[3]= "pqr";
    m.insert({4,"afg"});
    m[6];   // yahape isko likhne ki hi time complexity => O(log(n))
    //here 6 value will insert and compiler assign it by default 0 value.

    m[5]= "lmn"; // here due to unique key rule if print m[5]-> it will print new "lmn
     // value overriding previous declare m[5]="cdc"
    
    // here total time complexity = num of keys* O(log(n))

    cout<< m.size()<<endl; // size of map

    map<int,string> ::iterator it;  
    for(it=m.begin(); it != m.end(); ++it){
         cout << (*it).first << " "<< (*it).second;
    }
             // OR
    for(auto &pr: m){
        cout<<pr.first() << " " << pr.second()<<endl;
    } 

 // ** find function ** //
    auto it = m.find(3) // time complexity for searching is also O(log(n));
      //find operation will search for 3 and will return its iterator
    // and if value given in input is not present in map it will return m.end()
    // m.end() is last iterator ka agla iterator that is none value
    
    if(it == m.end()){
        cout<< "no value";
    }
    else{
        cout<< (*it).first() << " " << (*it).second();
        }
    // output= 3 pqr
    //  if input value m.find(7) -> output -> no value


// erase function
m.erase(3); // O(log(n))
  // we cannot give the value in erase which is not present in map it will give segmentation fault. 
}

int main(){
      map<int,string > m;

      m["abcde"] = "pqurs" // time complexity for this line -> s.size()* O(log(n))
}



