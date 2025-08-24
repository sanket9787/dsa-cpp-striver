#include <iostream>
#include <math.h>
using namespace std;

int fact(int n)

{
int fact=1;
for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}




int main()
{
    
int n1;
cin>>n1;
int ans=fact(n1);
cout<<ans<<endl;
return 0;

}
