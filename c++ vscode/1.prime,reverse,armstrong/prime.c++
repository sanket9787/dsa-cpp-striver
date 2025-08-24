#include <iostream>
using namespace std;

int main()
{
    int n;
    bool f=0;
    cin>>n;
    for(int i=2;i<n;i++)
    {
        if(i%n==0)
        {
            cout<< "not prime"<< endl;
            f=1;
        } 
      break;
      
    }
    
    if(f==0)
    {
        cout<<"prime"<<endl;
    }
   

}
