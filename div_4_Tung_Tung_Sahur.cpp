#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        int n = p.size(), m = s.size();
        int i = 0, j = 0;
        bool ok = true;

        while (i < n && j < m) {
            if (p[i] != s[j]) {
                ok = false;
                break;
            }
            ++j;
            if (j < m && s[j] == p[i]) {
                ++j;
            }
            ++i;
        }
        if (i != n || j != m) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
