#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> d, h;
vector<pair<int, int>> edges;
vector<int> cut, path;
int mark = 1;

void dfs(int v, int p, int n)
{
    used[v] = true;
    d[v] = h[v] = (p == -1 ? 0 : d[p] + 1);
    if (v == n)
        mark = 0;
    for (auto e : g[v])
    {
        int to = edges[e].first + edges[e].second - v;
        if (to == p)
            continue;
        if (used[to])
            h[v] = min(h[v], d[to]);
        else
        {
            path[e] ^= mark;
            dfs(to, v, n);
            path[e] ^= mark;
            h[v] = min(h[v], h[to]);
            if (h[to] > d[v])
                cut[e] = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        g.assign(n + 1, {});
        used.assign(n + 1, false);
        d.assign(n + 1, 0);
        h.assign(n + 1, 0);
        edges = {};
        cut.assign(m, false);
        path.assign(m, false);
        mark = 1;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, b});
            g[a].push_back(i);
            g[b].push_back(i);
        }

        dfs(1, -1, n);

        vector<int> ans(n + 1, n + m);
        vector<int> dist(n + 1, n + m);
        queue<int> q;
        for (int i = 0; i < m; ++i)
        {
            if (cut[i] && path[i])
            {
                ans[edges[i].first] = min(ans[edges[i].first], i + 1);
                ans[edges[i].second] = min(ans[edges[i].second], i + 1);
                if (dist[edges[i].first])
                {
                    dist[edges[i].first] = 0;
                    q.push(edges[i].first);
                }
                if (dist[edges[i].second])
                {
                    dist[edges[i].second] = 0;
                    q.push(edges[i].second);
                }
            }
        }

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto e : g[v])
            {
                int to = edges[e].first + edges[e].second - v;
                if (dist[to] > dist[v] + 1)
                {
                    dist[to] = dist[v] + 1;
                    ans[to] = ans[v];
                    q.push(to);
                }
                else if (dist[to] == dist[v] + 1)
                    ans[to] = min(ans[to], ans[v]);
            }
        }

        int Q;
        cin >> Q;
        while (Q--)
        {
            int v;
            cin >> v;
            if (ans[v] == n + m)
                cout << -1;
            else
                cout << ans[v];
            if (t || Q)
                cout << '\n';
        }
    }

    return 0;
}