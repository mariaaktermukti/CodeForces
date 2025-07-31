#include <bits/stdc++.h>
using namespace std;

struct BIT 
{
    int n;
    vector<int> f;
    BIT(int _n): n(_n), f(n+1,0){}
    void upd(int i,int v)
    {
        for(;i<=n;i+=i&-i)f[i]+=v;
    }
    int qry(int i)
    {int s=0;
        for(;i>0;i-=i&-i)
        s= s + f[i];
        return s;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> p(n+1);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
        }
        vector<long long> L(n+1), R(n+1);
        BIT bit1(n), bit2(n);
        for(int i=1;i<=n;i++)
        {
            L[i] = bit1.qry(n)-bit1.qry(p[i]);
            bit1.upd(p[i],1);
        }
        for(int i=n;i>=1;i--)
        {
            R[i]=bit2.qry(p[i]-1);
            bit2.upd(p[i],1);
        }

        long long A=0;
        for(int i=1;i<=n;i++)
        {
            A= A + R[i];
        }
        long long cost=A;
        for(int i=1;i<=n;i++)
        {
            long long w=(n-i)-R[i]-L[i];
            if(w<0)
            {
                cost= cost + w;
            }
        }
        cout << cost <<" \n";
    }
    return 0;
}
