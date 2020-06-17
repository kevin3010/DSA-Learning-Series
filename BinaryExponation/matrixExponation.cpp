// https://github.com/kevin3010
// https://www.codechef.com/problems/TILE
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF INT_MAX
#define MOD 1000000007
#define bound 100002
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
// memset(a, 0, sizeof(a)); 

ll binaryExponation(ll m)
{
    ll ans[2][2] = {{1ll,0ll},{0ll,1ll}};
    ll temp[2][2];
    ll n[2][2] = {{1ll,1ll},{1ll,0ll}}; 

    m=m-1;

    while(m)
    {
        if(m%2==1)  
        {
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    temp[i][j] = ans[i][j];
            
            ans[0][0] = (temp[0][0]*n[0][0] + temp[0][1]*n[1][0])%MOD;
            ans[0][1] = (temp[0][0]*n[0][1] + temp[0][1]*n[1][1])%MOD;
            ans[1][0] = (temp[1][0]*n[0][0] + temp[1][1]*n[1][0])%MOD;
            ans[1][1] = (temp[1][0]*n[0][1] + temp[1][1]*n[1][1])%MOD; 

        }
        for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    temp[i][j] = n[i][j];

        n[0][0] = (temp[0][0]*temp[0][0] + temp[0][1]*temp[1][0])%MOD;
        n[0][1] = (temp[0][0]*temp[0][1] + temp[0][1]*temp[1][1])%MOD;
        n[1][0] = (temp[1][0]*temp[0][0] + temp[1][1]*temp[1][0])%MOD;
        n[1][1] = (temp[1][0]*temp[0][1] + temp[1][1]*temp[1][1])%MOD; 
        m/=2;
    }

    return (ans[0][0]+ans[0][1])%MOD;
}

int main()
{
    fast;
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        cout<<binaryExponation(n)<<endl;
    }
}
