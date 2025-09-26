#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<vector<int64>> prev(n + 1, vector<int64>(n + 1, 0));
        vector<vector<int64>> cur(n + 1, vector<int64>(n + 1, 0));

        prev[0][0] = 1;

        for (int idx = 0; idx < n; ++idx)
        {
            int v = a[idx];
            for (int i = 0; i <= n; ++i)
                fill(cur[i].begin(), cur[i].end(), 0);

            for (int m = 0; m <= n; ++m)
            {
                for (int mp = 0; mp <= n; ++mp)
                {
                    int64 ways = prev[m][mp];
                    if (!ways)
                        continue;

                    cur[m][mp] += ways;
                    if (cur[m][mp] >= MOD)
                        cur[m][mp] -= MOD;

                    if (v >= m)
                    {
                        cur[v][mp] += ways;
                        if (cur[v][mp] >= MOD)
                            cur[v][mp] -= MOD;
                    }
                    else
                    {
                        if (v >= mp)
                        {
                            cur[m][v] += ways;
                            if (cur[m][v] >= MOD)
                                cur[m][v] -= MOD;
                        }
                    }
                }
            }
            prev.swap(cur);
        }

        int64 ans = 0;
        for (int m = 0; m <= n; ++m)
            for (int mp = 0; mp <= n; ++mp)
            {
                ans += prev[m][mp];
                if (ans >= MOD)
                    ans -= MOD;
            }

        cout << ans % MOD << '\n';
    }
    return 0;
}
