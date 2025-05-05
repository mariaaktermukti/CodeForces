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
        array<int, 4> cnt = {0, 0, 0, 0};
        for (char c : s) {
            if (c == 'A') cnt[0]++;
            else if (c == 'B') cnt[1]++;
            else if (c == 'C') cnt[2]++;
            else if (c == 'D') cnt[3]++;
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans += min(cnt[i], n);
        }

        cout << ans << "\n";
    }

    return 0;
}
