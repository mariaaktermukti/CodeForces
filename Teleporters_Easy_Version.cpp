#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> cost(n);
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            cost[i] = a + (i + 1);
        }

        sort(cost.begin(), cost.end());
        ll used = 0;
        int cnt = 0;
        for (ll x : cost) {
            if (used + x > c) break;
            used += x;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}
