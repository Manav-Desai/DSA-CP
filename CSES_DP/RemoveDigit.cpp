#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    int n;
    cin>>n;

    if(n <= 9)
    {
        cout<<1<<"\n";
        return 0;
    }

    vector<int> dp(n+1 , INT_MAX - 2);
    int temp , rem;

    dp[0] = 0;

    for(int i=1 ; i<=n ; i++)
    {
        temp = i;

        while(temp > 0)
        {
            rem = temp % 10;
            temp = temp / 10;

            dp[i] = min(dp[i] ,1 + dp[i - rem]);
        }
    }

    cout<<dp[n]<<"\n";

    return 0;
}