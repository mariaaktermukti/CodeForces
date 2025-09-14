#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++)
        {
            pos[b[i]].push_back(i);
        }

        bool ok = true;
        for (int x = 1; x <= n; x++)
        {
            if (pos[x].size() % x != 0)
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << "\n";
            continue;
        }

        vector<int> ans(n, 0);
        int z = 1;

        for (int x = 1; x <= n; x++)
        {
            auto &vec = pos[x];
            for (int i = 0; i < (int)vec.size(); i++)
            {
                ans[vec[i]] = z;
                if ((i + 1) % x == 0)
                    z++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
