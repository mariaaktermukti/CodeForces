#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{  
    int T; 
    if (!(cin >> T)) return 0;
    while (T--)
    {
        int n; cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> deg(n+1, 0);
        for (int i = 0; i < n-1; ++i) 
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        if (n == 2) 
        { 
            cout << 0 << '\n';
            continue;
        }
        int totalLeaves = 0;
        for (int i = 1; i <= n; ++i) if (deg[i] == 1) ++totalLeaves;
        
        int ans = INT_MAX;
        for (int r = 1; r <= n; ++r) 
        {
            int neighLeafCount = 0;
            for (int v : g[r]) 
            {
                if (deg[v] == 1) ++neighLeafCount;
            }
            int isLeafR = (deg[r] == 1) ? 1 : 0;
            int cand = totalLeaves - isLeafR - neighLeafCount;
            if (cand < 0) cand = 0;
            ans = min(ans, cand);
        }
        cout << ans << '\n';
    }
    return 0;
}
