#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(2 * n);
        for (ll &x : v)
            cin >> x;

        vector<ll> ans(n + 1, 0);

        for (ll i = 0; i < 2 * n; i += 2)
            ans[1] -= v[i];
        for (ll i = 1; i < 2 * n; i += 2)
            ans[1] += v[i], ans[2] -= v[i];
        for (ll i = 2; i < 2 * n; i += 2)
            ans[2] += v[i];
        ans[2] += 2 * v.back() - v[0];

        for (ll i = 3; i <= n; i++)
            ans[i] = ans[i - 2] + 2 * (v[2 * n - i + 1] - v[i - 2]);

        for (ll i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}
