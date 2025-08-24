#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

//  string str = "abc";
//  vector< int > v(256,0);
// for(int i =0; i<str.length(); i++)
// {
//     v[str[i]]++;

// }
// cout << v[96] << " " << v[97] <<endl;

int a = 8;
int &b = a;
cout << b << " " << &b << " "<< &a << endl;
int *ptr = &a;
cout << *ptr <<" " << ptr << " " << &ptr;
}