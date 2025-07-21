#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int ans=0,rem=0;
        ans= ans + min(m,a);rem+=m-min(m,a);
        ans= ans + min(m,b);rem+=m-min(m,b);
        ans= ans + min(rem,c);
        cout<<ans<<'\n';
    }
    return 0;
}