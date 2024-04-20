#include <iostream>
using namespace std;
 
int gcd(int a,int b)
{
    // base case:
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

int lcm(int a,int b)
{
    int gc = gcd(a,b);
    int lcm = (a * b) / gc;
    return lcm;
}

int main()
{
    int a,b;
    cout<<"Enter 2 numbers : ";
    cin>>a>>b;

    cout<<"GCD of 2 numbers : "<<gcd(a,b)<<endl;
    cout<<"LCM of 2 numbers : "<<lcm(a,b)<<endl;
    return 0;
}