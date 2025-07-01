#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        int mx = 0, cnt_mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] > mx) {
                    mx = a[i][j], cnt_mx = 1;
                } else if (a[i][j] == mx) {
                    cnt_mx++;
                }
            }
        }
        vector<int> r(n), c(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == mx) {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (r[i] + c[j] - (a[i][j] == mx) == cnt_mx) {
                    flag = 1;
                }
            }
        }
        cout << mx - flag << '\n';
    }
    return 0;
}