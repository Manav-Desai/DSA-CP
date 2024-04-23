#include <iostream>
#include <vector>
using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int n , sum;
    cin>>n>>sum;

    int deno[n];

    for(int i=0 ; i<n ; i++)
        cin>>deno[i];


// dp[i] denotes the number of ways to make the sum using all the possible combinations of deno.
    vector<int> dp(sum+1,0);

    dp[0] = 1;

    for(int i=1 ; i<=sum ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(deno[j] <= i)
                dp[i] = (dp[i] + dp[i - deno[j]]) % MOD;
            
        }
    }

    cout<<dp[sum]<<"\n";

    return 0;
}