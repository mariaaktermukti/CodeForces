#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(1001, -1);  
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;  
    }

    int ans = -1;

    for (int i = 1; i <= 1000; ++i) {
        if (pos[i] == -1) continue;
        for (int j = 1; j <= 1000; ++j) {
            if (pos[j] == -1) continue;
            if (__gcd(i, j) == 1) {
                ans = max(ans, pos[i] + pos[j]);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
