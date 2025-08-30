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
        vector<vector<int>> G(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<int> dist(n, 0), parent(n, -1);
        function<void(int, int)> dfs = [&](int u, int p)
        {
            parent[u] = p;
            for (int v : G[u])
                if (v != p)
                {
                    dist[v] = dist[u] + 1;
                    dfs(v, u);
                }
        };

        dist.assign(n, 0);
        dfs(0, -1);
        int x = max_element(dist.begin(), dist.end()) - dist.begin();

        dist.assign(n, 0);
        dfs(x, -1);
        int y = max_element(dist.begin(), dist.end()) - dist.begin();

        if (dist[y] == n - 1)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<int> on_diameter(n, 0);
        int cur = y;
        while (cur != -1)
        {
            on_diameter[cur] = 1;
            cur = parent[cur];
        }

        int a = -1, b = -1, c = -1;
        for (int u = 0; u < n; ++u)
        {
            if (!on_diameter[u])
                continue;
            for (int v : G[u])
            {
                if (!on_diameter[v])
                {
                    a = parent[u];
                    b = u;
                    c = v;
                    break;
                }
            }
            if (a != -1)
                break;
        }

        if (a == -1)
        {
            for (int u = 0; u < n && a == -1; ++u)
            {
                if (!on_diameter[u])
                    continue;
                for (int v : G[u])
                {
                    if (!on_diameter[v])
                    {
                        b = u;
                        c = v;
                        for (int w : G[b])
                            if (on_diameter[w])
                            {
                                a = w;
                                break;
                            }
                        break;
                    }
                }
            }
        }
        cout << (a + 1) << ' ' << (b + 1) << ' ' << (c + 1) << '\n';
    }
    return 0;
}
