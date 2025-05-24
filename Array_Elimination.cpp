#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> bit_count(30, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 30; ++j) {
                if (a[i] & (1 << j)) {
                    bit_count[j]++;
                }
            }
        }

        int gcd_all = 0;
        for (int i = 0; i < 30; ++i) {
            gcd_all = __gcd(gcd_all, bit_count[i]);
        }

        vector<int> ans;
        for (int k = 1; k <= n; ++k) {
            if (gcd_all % k == 0) {
                ans.push_back(k);
            }
        }

        for (int k : ans) {
            cout << k << ' ';
        }
        cout << '\n';
    }

    return 0;
}
