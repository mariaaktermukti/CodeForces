#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll x = -1;
        bool ok = true;
        for (int i = 0; i < n; i++) 
        {
            if (b[i] != -1)
            {
                ll sum = a[i] + b[i];
                if (x == -1) x = sum;
                else if (x != sum) 
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) 
        {
            cout << 0 << '\n';
            continue;
        }
        if (x != -1) 
        {
            for (int i = 0; i < n; i++) 
            {
                if (b[i] == -1) 
                {
                    ll bi = x - a[i];
                    if (bi < 0 || bi > k) 
                    {
                        ok = false;
                        break;
                    }
                }
            }
            cout << (ok ? 1 : 0) << '\n';
        } 
        else 
        {
            ll L = 0, R = 2 * k;
            ll low = a[0], high = a[0] + k;
            for (int i = 1; i < n; i++) 
            {
                low = max(low, a[i]);
                high = min(high, a[i] + k);
            }
            ll ans = 0;
            if (low <= high) ans = high - low + 1;
            cout << ans << '\n';
        }
    }
    return 0;
}
