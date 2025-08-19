#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 200000 + 5;
long long fact[MAXN];

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}

long long solve_case(int n, int m, vector<vector<int>> &g)
{
    if (m != n - 1)
        return 0;

    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++)
        deg[i] = g[i].size();

    if (n == 2)
        return 2; 

    vector<int> nonleaf;
    for (int i = 1; i <= n; i++)
        if (deg[i] > 1)
            nonleaf.push_back(i);

    for (int u = 1; u <= n; u++)
    {
        int cnt = 0;
        for (int v : g[u])
            if (deg[v] > 1)
                cnt++;
        if (cnt >= 3)
            return 0;
    }

    if (nonleaf.size() == 1)
    {
        return (2 * fact[n - 1]) % MOD;
    }

    if (nonleaf.size() == 2)
    {
        int u = nonleaf[0], v = nonleaf[1];
        bool adj = false;
        for (int x : g[u])
            if (x == v)
                adj = true;
        if (!adj)
            return 0;

        long long ans = 4;
        ans = (ans * fact[deg[u] - 1]) % MOD;
        ans = (ans * fact[deg[v] - 1]) % MOD;
        return ans;
    }

    long long ans = 4;
    for (int u : nonleaf)
    {
        int leafs = 0;
        for (int v : g[u])
            if (deg[v] == 1)
                leafs++;
        ans = (ans * fact[leafs]) % MOD;
    }
    return ans;
}

int main()
{
    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << solve_case(n, m, g) << "\n";
    }
}
