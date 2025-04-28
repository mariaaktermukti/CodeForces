#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll ans = 0;
        ll length = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= q) {
                length++;
            } else {
                if (length >= k) {
                    ll temp = length - k + 1;
                    ans += (temp * (temp + 1)) / 2;
                }
                length = 0;
            }
        }
        if (length >= k) {
            ll temp = length - k + 1;
            ans += (temp * (temp + 1)) / 2;
        }

        cout << ans << '\n';
    }
    return 0;
}
