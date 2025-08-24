#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> v={3,5,6,7};

    vector<int> ::iterator it;  //iterator is define here
    for(it=v.begin(); it!=v.end(); ++it)
    {
        cout<<(*it)<<endl;
    }
    // output= 3 5 6 7
}
// there is difference between it++ and it+1 
// it++ it will move to the next iterator 
// it+1 will move to next location 
// this both are valid in case of vector because vector is continous 
// but in case of maps they are not continous so it+1 is not valid over there.

int main(){
   // iterator for vector pair->
   vector<pair<int,int> > vp= {{1,2},{2,3},{3,4}};
   vector<pair<int,int> > ::iterator it;    //iterator is define here

   for(it=vp.begin(); it!=vp.end();++it){
       cout<< (*it).first() << (*it).second();
  } 
   for(it=vp.begin(); it!=vp.end();++it){
       cout<< it->first << it->second;
  } 
   // (*it).first == it->first
}

int main(){
    //short method to write code for iterators

      vector<int> v={3,5,6,7};
      vector<int> ::iterator it; 
       for(int value : v){
           cout<< value <<" ";
       }
     //output= 3,5,6,7
       //yahape value me vector ke copy aa rahi hai actual elements lane ke liye us &value

       for(int &value : v){
           value++;
       }
      for(int value : v){
           cout<< value <<" ";
       }
    //    output = 4,6,7,8

//for vector pairs short method for iterators
 
   vector<pair<int>> vp={{1,2},{3,4}};
    vector<pair<int,int> > ::iterator it;

   for(pair <int,int> &value: vp){
       cout << value.first << " " << value.second;
    }
   //output = 1 2  1 3

}
 
// auto keyword -> it automatically determines what type of data tyep variable has 
// auto a=1.0, auto a=1;

   //so we need not to define the iterator 
   int main(){
       vector<int> v={3,5,6,7};
       
       //without using any declaration of iterator it
      for(auto it=v.begin(); it!=v.end(); ++it)
      {cout<<(*it)<<endl;}
              //or
      for(auto value : v){
           cout<< value <<" ";
       }
//   for vector pair
      vector<pair<int,int> > vp= {{1,2},{2,3},{3,4}};

       for(auto pair <int,int> &value: vp){
       cout << value.first << " " << value.second;
    }
    //    output= 1 2  2 3  3 4
   }