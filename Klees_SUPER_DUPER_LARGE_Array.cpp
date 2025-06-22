#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll prefix_sum(ll k, ll i) {
    return i * (2 * k + i - 1) / 2;
}

ll compute_x(ll n, ll k, ll i) {
    ll total = n * (2 * k + n - 1) / 2;
    ll prefix = prefix_sum(k, i);
    return abs(2 * prefix - total);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll lo = 1, hi = n;
        ll ans = LLONG_MAX;

        while (hi - lo > 3) {
            ll m1 = lo + (hi - lo) / 3;
            ll m2 = hi - (hi - lo) / 3;
            ll x1 = compute_x(n, k, m1);
            ll x2 = compute_x(n, k, m2);
            if (x1 < x2) {
                hi = m2 - 1;
            } else {
                lo = m1 + 1;
            }
        }

        for (ll i = lo; i <= hi; ++i) {
            ans = min(ans, compute_x(n, k, i));
        }

        cout << ans << "\n";
    }

    return 0;
}
