#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            long long x, y;
            cin >> u >> v >> x >> y;
            if (x <= y)
            {
                g[u].push_back(v);
                indeg[v]++;
            }
            else
            {
                g[v].push_back(u);
                indeg[u]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> topo;
        topo.reserve(n);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            topo.push_back(v);
            for (int to : g[v])
            {
                if (--indeg[to] == 0)
                    q.push(to);
            }
        }

        vector<int> p(n + 1, 0);
        for (int i = 0; i < (int)topo.size(); ++i)
        {
            p[topo[i]] = i + 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
