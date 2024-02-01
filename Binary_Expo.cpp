#include <iostream>
using namespace std;

#define ll long long

ll binary_expo_recursive( ll a,ll b)
{
    // base case:
    if(b == 0)
        return 1;
    
    ll ans = binary_expo_recursive(a,b/2);

    if(b % 2 == 0)
        return (1LL * ans * ans);
    else
        return (1LL * ans * ans * a);
}

ll binary_expo_iterative(ll a,ll b)
{
    // base case:
    if(b == 0)
        return 1;
    
    ll ans = 1;

    while(b > 0)
    {
        if(b % 2 == 1)
        {
            ans = ans * a;
        }

        a = a*a;
        b = b/2;
    }

    return ans;
}

int main()
{
    ll a,b;
    cout<<"Enter 2 numbers : ";
    cin>>a>>b;

    cout<<"Recursive : "<<binary_expo_recursive(a,b)<<endl;
    cout<<"Iterative : "<<binary_expo_iterative(a,b)<<endl;

    return 0;
}