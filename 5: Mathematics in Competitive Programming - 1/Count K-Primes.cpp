// modified sieve
// prefix sum

// while calculating the sieve add the total primes factor to that number.
// then calculate the prefix sum of the for k=1to5 

// https://github.com/kevin3010
// https://www.codechef.com/LRNDSA05/problems/KPRIME

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll primes[1000001];

void sieve()
{
    for(int i=0;i<1000001;i++) primes[i]=0;

    primes[0]=0;
    primes[1]=0;

    // for(int i=0;i<201;i++) cout<<primes[i]<<" ";

    for(int i=2;i<1000001;i++)
    {
        if(primes[i]==0)
        {
            primes[i]+=1;
            for(int j=i*2;j<1000001;j+=i)
            {
                primes[j]+=1;
            }
        }
    }

    // for(int i=1;i<50;i++)
    //     cout<<i<<" :: "<<primes[i]<<endl;

}

std::vector<ll> v[5];

void prefixSum()
{
    for(int i=0;i<5;i++)
    {
        v[i].push_back(0);
        v[i].push_back(0);
        for(int j=2;j<1000001;j++)
        {
            v[i].push_back(v[i][j-1]+(primes[j]==(i+1)));
        }
    }

    // int i=0;
    // cout<<"factors list"<<endl;
    // for(auto j:v[1])
    // {
    //     cout<<i<<" "<<j<<endl;

    //     if((++i)==50) break;
    // }
}




#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
// memset(a, 0, sizeof(a)); 
int main()
{
    sieve();
    prefixSum();

    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;

        cout<<v[k-1][b]-v[k-1][a-1]<<endl;
    }
}
