#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> G(n, vector<int>(n));
        vector<vector<int>> sumToValues(2 * n + 1); 

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> G[i][j];
                sumToValues[i + j + 1].push_back(G[i][j]); // i+j+1 for 1-based p index
            }

        vector<int> p(2 * n + 1); // p[1..2n]
        vector<bool> used(2 * n + 1, false); // used[1..2n]

        for (int k = 1; k <= 2 * n; ++k) {
            for (int x : sumToValues[k]) {
                if (!used[x]) {
                    p[k] = x;
                    used[x] = true;
                    break;
                }
            }
        }

        for (int i = 1; i <= 2 * n; ++i)
            cout << p[i] << " ";
        cout << '\n';
    }

    return 0;
}
