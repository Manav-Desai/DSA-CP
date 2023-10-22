#include <iostream>
using namespace std;

int binaryexpo_iterative(int a,int b,long long mod)
{
    int ans = 1;
    
    while(b){
        
        if(b&1)
            ans = (ans * 1LL * a) % mod;
        
        a = (a*1LL*a)%mod;
        b = b>>1;
    }
    
    return ans;
}

int binaryexpo_recursive(int a,int b,long long mod)
{
    //base case:
    if(b == 0)
        return 1;
    
    int res = binaryexpo_recursive(a,b/2,mod);

    if(b%2 == 0)
        return (res * 1LL * res) % mod;
    else
        return (a * res * 1LL * res) % mod;
}


int main()
{
    int a,b;
    cout<<"Enter 2 numbers : ";
    cin>>a>>b;

    long long mod = 1e9 + 7;

    cout<<"Recursive Binary Expo : "<<binaryexpo_recursive(a,b,mod);
    cout<<"Iterative Binary Expo : "<<binaryexpo_iterative(a,b,mod);
    
    return 0;
}
