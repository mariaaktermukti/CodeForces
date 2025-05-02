#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        int n;
        cin >> a >> b >> n;

        long long ans = b;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            ans += min(a - 1, x);
        }
        cout << ans << "\n";
    }

    return 0;
}
