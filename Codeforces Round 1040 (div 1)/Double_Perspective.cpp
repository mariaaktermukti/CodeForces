#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

        vector<int> tag(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (a[j] <= a[i] && b[i] <= b[j]) {
                    tag[i] = 0;
                    break; 
                }
            }
        }

        vector<int> ans;
        for (int i = 1; i <= n; ++i) if (tag[i]) ans.push_back(i);

        cout << ans.size() << '\n';
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
