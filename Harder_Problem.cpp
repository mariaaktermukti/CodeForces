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
        int n;
        cin>>n;
        vector<int> a(n+1),b(n);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(!a[x])
            {
                b[i]=x;
                a[x]=1;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(!a[i])
            {
                q.push(i);
            }
        }
                     
        for(int i=0;i<n;i++)
        {
            if(!b[i])
            {
                b[i]=q.front();
                q.pop();
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<b[i]<<" \n"[i==n-1];
        }
            
    }
    return 0;
}