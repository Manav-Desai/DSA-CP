#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> sieve_prime(int n)
{
	bool sieve[n+1];

	for(int i=2 ; i<=n ; i++)
		sieve[i] = true;

	for(ll i=2 ; i*i<=n ; i++)
	{
		if(sieve[i])
		{
			for(int j=i*i ; j<=n ; j+=i)
				sieve[j] = false;
		}
	}

	vector<int> primes;

	for(int i=2 ; i<=n ; i++)
		if(sieve[i])
			primes.push_back(i);

	return primes;
}

void segmented_sieve(int l,int h)
{
    vector<int> primes = sieve_prime(sqrt(h));
    vector<int> ans;
    bool dummy[h - l + 1];

    for(int i=0 ; i<(h - l + 1) ; i++)
        dummy[i] = true;
    

    for(auto pr : primes)
    {
        int firstMultiple = (l/pr) * pr;

        if(firstMultiple < l) firstMultiple += l;

        for(int j=max(pr*pr,firstMultiple) ; j<=h ; j+=pr)
        {
            dummy[j-l] = false;
        }
    }

    for(int i=l ; i<=h ; i++)
    {
        if(dummy[i-l])
            cout<<i<<" ";
    }

    return;
}
int main()
{
    ll l,h;
    cout<<"Enter the lower and upper limit to generate prime : ";
    cin>>l>>h;

    segmented_sieve(l,h);

    return 0;
}