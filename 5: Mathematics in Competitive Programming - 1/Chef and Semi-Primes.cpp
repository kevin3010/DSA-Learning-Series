// https://www.codechef.com/LRNDSA05/problems/CHEFPRMS
// https://github.com/kevin3010

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
// memset(a, 0, sizeof(a));

int primes[201];

void sieve()
{
    for(int i=0;i<201;i++) primes[i]=1;

    primes[0]=0;
    primes[1]=0; 

    // for(int i=0;i<201;i++) cout<<primes[i]<<" ";

    for(int i=2;i<201;i++)
    {
        if(primes[i]==1)
        {
            for(int j=i*2;j<201;j+=i)
            {
                primes[j]=0;
            }
        }
    }

    // for(int i=0;i<201; i++)
    //     if(primes[i])
    //         cout<<i<<" "; 
} 

std::vector<int> semi_primes;

void findSemiPrimes()
{
    for(int k=2;k<201;k++)
    {
        for(int i=2;i<=sqrt(k);i++)
        {
            if(k%i==0)
            {
                // cout<<i<<" ";
                if(k/i != i)
                {
                    if(primes[i]==1 && primes[k/i]==1)
                        {semi_primes.push_back(k); break;}
                }
            }
        }

    }    
}

std::vector<int> combinations;
void semiPrimesCombination()
{
    for(int i=0;i<semi_primes.size();i++)
    {
        for(int j=i;j<semi_primes.size();j++)
        {
            // cout<<semi_primes[i]+semi_primes[j]<<" ";
            combinations.push_back(semi_primes[i]+semi_primes[j]);
        }
    }
}



int main()
{
    sieve();

    findSemiPrimes();
    semiPrimesCombination();

    sort(combinations.begin(),combinations.end());

    int t;
    cin>>t;

    // for(auto i:combinations)
    //     cout<<i<<" ";

    while(t--)
    {

        int temp;
        cin>>temp;
        if(binary_search(combinations.begin(),combinations.end(),temp))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    // for(auto i:combinations) cout<<i<<" ";
}
