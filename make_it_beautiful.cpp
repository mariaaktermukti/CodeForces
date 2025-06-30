#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 0;
    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
        ans += __builtin_popcountll(i);
    }
    for (int j = 0; j <= 60; j++) {
        ll bb = (1ll<<j);
        for (ll x : a) {
            if (!(x & bb) && k >= bb) {
                ans++;
                k -= bb;
            }
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}