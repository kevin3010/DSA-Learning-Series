//https://www.youtube.com/watch?v=HG2Ex8JdXGU

// https://github.com/kevin3010
// https://www.codechef.com/PRACTICE/problems/ENGXOR


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;


#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
// memset(a, 0, sizeof(a)); 



ll updateEvenOdd(ll number)
{
    ll count=0;
    while(number)
    {
        number = number & (number-1);
        count++;
    }

    return count;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;

    // cout<<updateEvenOdd(t);

    while(t--)
    {
        ll n,q;
        cin>>n>>q;

        ll temp;
        ll even=0;
        ll odd=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            ll count = updateEvenOdd(temp);
            if(count%2==1) odd++;
            else even++;
        }

        while(q--)
        {
            ll p;
            cin>>p;

            ll count = updateEvenOdd(p);

            if(count%2==1) cout<<odd<<" "<<even<<"\n";
            else cout<<even<<" "<<odd<<"\n";
        }
    }
}
