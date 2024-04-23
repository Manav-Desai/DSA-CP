#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7; 

int main()
{
    int n,sum;
    cin>>n>>sum;

    int deno[n];

    for(int i=0 ; i<n ; i++)
        cin>>deno[i];
    
    vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));

    // initalisation of base case:

    for(int i=0 ; i<=sum ; i++)
        dp[0][i] = INT_MAX - 1;
    
    for(int i=0 ; i<=n ; i++)
        dp[i][0] = 0;
    

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=sum ; j++)
        {
            if(deno[i-1] <= j)
            {
                dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j - deno[i-1] ]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][sum] == (INT_MAX - 1) || dp[n][sum] == INT_MAX)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<dp[n][sum]<<"\n";
    }

    return 0;
}