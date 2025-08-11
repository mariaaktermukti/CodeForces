#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,k,a[400009],stk[400009];

inline ll read()
{
	ll s = 0,w = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
    { 
        if (ch == '-') w = -1; 
        ch = getchar();
    }
	while (ch <= '9' && ch >= '0') s = (s << 1) + (s << 3) + (ch ^ 48),ch = getchar();
	return s * w;
}
int main()
{
	t = read();
	while (t --)
    {
		n = read(),k = read();
		for (ll i = 1;i <= n;i += 1) a[i] = read();
		for (ll i = 1;i <= n;i += 1) a[i] = a[i + n] = a[i] - read();
		for (ll i = 1;i <= 2 * n;i += 1) a[i] += a[i - 1];
		ll tp = 0,ans = 0;
		for (ll i = 2 * n;i >= 1;i -= 1)
        {
			while (tp && a[stk[tp]] > a[i]) tp -= 1;
			if (i <= n) ans = max(ans,stk[tp] - i);
			stk[++ tp] = i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}