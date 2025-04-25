#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> b(m+1);
        for (int i = 1; i <= m; i++) cin >> b[i];

        vector<int> L(m+1, n), R(m+2, -1);
        L[0] = -1;
        int pos = 0;
        for (int i = 1; i <= m; i++) {
            while (pos < n && a[pos] < b[i]) pos++;
            L[i] = (pos < n ? pos : n);
            if (pos < n) pos++;
        }
        if (L[m] < n) 
        {
            cout << 0 << "\n";
            continue;
        }
        R[m+1] = n;
        pos = n - 1;
        for (int i = m; i >= 1; i--) 
        {
            while (pos >= 0 && a[pos] < b[i]) pos--;
            R[i] = (pos >= 0 ? pos : -1);
            if (pos >= 0) pos--;
        }
        ll ans = LLONG_MAX;
        for (int j = 1; j <= m; j++) 
        {
            if (L[j-1] < R[j+1]) 
            {
                ans = min(ans, b[j]);
            }
        }
        if (ans == LLONG_MAX) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
