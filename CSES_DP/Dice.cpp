#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

// recursion with memoization
int solve(int sum , vector<int> &dp)
{
    if(sum == 0)
        return 1;
    else if(sum < 0)
        return 0;
    
    if(dp[sum] != -1)
        return dp[sum];
    
    int ways = 0;

    for(int j=1 ; j<=6 ; j++)
    {
        ways = (ways % mod + solve(sum - j , dp) % mod ) % mod;
    }

    return dp[sum] = ways;
} 

int main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1 , -1);

    // cout<<solve(n , dp)<<"\n";

    dp[0] = 1;

    for(int i=1 ; i<=n ; i++)
    {
        dp[i] = 0;

        for(int j=1 ; j<=6 ; j++)
        {
            if(j > i)
                break;
            
            dp[i] = ( dp[i] % mod + dp[i-j] % mod ) % mod;
        }
    }

    cout<<dp[n]<<"\n";

    return 0;
}