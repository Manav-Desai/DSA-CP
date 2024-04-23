#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    int n,sum;
    cin>>n>>sum;

    vector<int> deno(n);

    for(int i=0 ; i<n ; i++)
        cin>>deno[i];

    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));

    for(int i=0 ; i<=n ; i++)
        dp[i][0] = 1;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=sum ; j++)
        {
            if(deno[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-deno[i-1]] ) % mod;
            }
            else
            {
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }

    cout<<dp[n][sum]<<"\n";
    
    return 0;
}