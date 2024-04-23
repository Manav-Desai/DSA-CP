#include <bits/stdc++.h>
using namespace std;

// It is based on knapsack pattern 

int main()
{
    int n,cost;
    cin>>n>>cost;

    int wt[n] , val[n];

    for(int i=0 ; i<n ; i++)
        cin>>wt[i];
    
    for(int i=0 ; i<n ; i++)
        cin>>val[i];
    
    int dp[n+1][cost+1];

    for(int i=0 ; i<=cost ; i++)
        dp[0][i] = 0;
    
    for(int i=0 ; i<=n ; i++)
        dp[i][0] = 0;
    

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=cost ; j++)
        {
            if(wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][cost]<<"\n";
}