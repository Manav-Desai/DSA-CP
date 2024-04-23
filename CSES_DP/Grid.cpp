#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    int n;
    cin>>n;

    char grid[n][n];
    int dp[n][n];

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin>>grid[i][j];
            dp[i][j] = 0;
        }
    }

    // intialisation and edge case:

    if(grid[n-1][n-1] == '*')
    {
        cout<<0<<"\n";
        return 0;
    }

    if(grid[0][0] == '.')
        dp[0][0] = 1;

    for(int i=1 ; i<n ; i++)
    {
        if(grid[i][0] == '.')
            dp[i][0] = dp[i-1][0];
        
        if(grid[0][i] == '.')
            dp[0][i] = dp[0][i-1];
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int j=1 ; j<n ; j++)
        {
            if(grid[i][j] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout<<dp[n-1][n-1]<<"\n";
}