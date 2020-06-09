// https://github.com/kevin3010
// https://www.codechef.com/problems/MAXSEGM
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
// memset(a, 0, sizeof(a)); 
int main()
{   

    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n+1];
        ll b[n+1];
        ll prefix[n+1];
        prefix[0]=0;

        ll seen[n+1];
        for(int i=0;i<n+1;i++) seen[i]=0;

        for(int i=1;i<n+1;i++) cin>>a[i];
        for(int i=1;i<n+1;i++) cin>>b[i];
        for(int i=1;i<n+1;i++) prefix[i] = prefix[i-1]+b[i];

        ll maxi = -1;

        int i=1;
        int j=i;

        while(i<n+1)
        {
            while(i<n+1 && seen[a[i]]<j) 
            {
                seen[a[i]] = i;
                i++;
            }

            if(i==n+1) { maxi=max(maxi,prefix[i-1]-prefix[j-1]); break;}

            maxi=max(maxi,prefix[i-1]-prefix[j-1]);
            j=seen[a[i]]+1;
        }

        cout<<maxi<<endl;

    }
        



}
