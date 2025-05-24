#include "bits/stdc++.h"
#define all(a) a.begin(), a.end()
#define pb push_back
typedef long long ll;
using namespace std;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N = 100005;
 
void solve() {
    ll x;
    cin >> x;
    vector<int> res(31, 0);
    for (int i = 0; i < 30; i++) {
        if (1ll & (x >> i)) {
            if (res[i]) {
                res[i + 1] = 1;
                res[i] = 0;
            } else if (i > 0) {
                if (res[i - 1] == 1) {
                    res[i + 1] = 1;
                    res[i - 1] = -1;
                } else {
                    res[i] = 1;
                }
            } else if (i == 0) {
                res[i] = 1;
            }
        }
    }
    cout << 31 << '\n';
    for (int i = 0; i <= 30; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}