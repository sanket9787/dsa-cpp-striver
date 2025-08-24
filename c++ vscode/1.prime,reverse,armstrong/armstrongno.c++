#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    
int n,sum=0;

int originaln=n;
cin>>n;
while(n>0)
{
int lastdigit=n%10;
sum=sum+pow(lastdigit,3);
n=n/10;
}
 
 if(sum==originaln)
 {
     cout<<"armstrong no"<<endl;
 }
 else{
     cout<<"not armstrong"<<endl;
 }

}
