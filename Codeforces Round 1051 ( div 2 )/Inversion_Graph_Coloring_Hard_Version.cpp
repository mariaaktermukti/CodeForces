#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

inline void addSelf(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    int tc;
    if (!(cin >> tc))
        return 0;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            a[i] = 1;
            for (int j = 1; j < i; ++j)
                if (b[j] <= b[i])
                    ++a[i];
            for (int j = i + 1; j <= n; ++j)
                if (b[j] < b[i])
                    ++a[i];
        }
        vector<vector<int>> bit_lin(n + 1, vector<int>(n + 2, 0));
        vector<vector<int>> bit_col(n + 1, vector<int>(n + 2, 0));

        auto update_lin = [&](int lin, int pos, int val)
        {
            int i = pos + 1;
            while (i <= n + 1)
            {
                addSelf(bit_lin[lin][i], val);
                i += i & -i;
            }
        };
        auto update_col = [&](int col, int pos, int val)
        {
            int i = pos + 1;
            while (i <= n + 1)
            {
                addSelf(bit_col[col][i], val);
                i += i & -i;
            }
        };
        auto query_lin = [&](int lin, int pos) -> int
        {
            int i = pos + 1;
            int res = 0;
            while (i > 0)
            {
                addSelf(res, bit_lin[lin][i]);
                i -= i & -i;
            }
            return res;
        };
        auto query_col = [&](int col, int pos) -> int
        {
            int i = pos + 1;
            int res = 0;
            while (i > 0)
            {
                addSelf(res, bit_col[col][i]);
                i -= i & -i;
            }
            return res;
        };

        update_lin(0, 0, 1);
        update_col(0, 0, 1);

        for (int i = 1; i <= n; ++i)
        {
            int x = a[i];
            vector<tuple<int, int, int>> buffs;
            for (int j = x + 1; j <= n; ++j)
            {
                int buff = query_lin(j, x - 1);
                if (buff)
                    buffs.emplace_back(buff, j, x);
            }
            for (int q = 0; q < x; ++q)
            {
                int buff = query_col(q, x - 1);
                if (buff)
                    buffs.emplace_back(buff, x, q);
            }

            for (auto &t : buffs)
            {
                int val, lin, col;
                tie(val, lin, col) = t;
                update_lin(lin, col, val);
                update_col(col, lin, val);
            }
        }

        int ans = 0;
        for (int lin = 0; lin <= n; ++lin)
        {
            addSelf(ans, query_lin(lin, n));
        }
        cout << ans << '\n';
    }
    return 0;
}
