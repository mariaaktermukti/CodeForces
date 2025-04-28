#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int whites = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') whites++;
        }
        int ans = whites;
        for (int i = k; i < n; i++) {
            if (s[i] == 'W') whites++;
            if (s[i - k] == 'W') whites--;
            ans = min(ans, whites);
        }

        cout << ans << "\n";
    }

    return 0;
}
