#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long cnt1 = 0;
        for (char c : s) if (c == '1') cnt1++;
        long long cnt0 = n - cnt1;

        // Each '1' remains '1' in (n-1) rows except its own flip, each '0' becomes '1' exactly once.
        long long result = cnt1 * (n - 1) + cnt0;
        cout << result << '\n';
    }
    return 0;
}
