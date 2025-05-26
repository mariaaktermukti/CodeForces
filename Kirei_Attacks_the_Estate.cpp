#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n-1; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n+1, 0), order;
        order.reserve(n);
        queue<int> q;
        q.push(1);
        parent[1] = -1;
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            order.push_back(u);
            for(int v : adj[u]){
                if(parent[v]==0){
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        const ll INF = numeric_limits<ll>::max()/4;
        vector<ll> dp_even(n+1), dp_odd(n+1), threat(n+1);

        dp_even[1] = a[1];
        dp_odd [1] =  INF;  
        threat[1] = dp_even[1];

        for(int idx = 1; idx < n; idx++){
            int v = order[idx];
            int u = parent[v];

            ll e = max(a[v], a[v] - dp_odd[u]);
            ll o = a[v] - dp_even[u];

            dp_even[v] = e;
            dp_odd [v] = o;
            threat[v] = max(e, o);
        }

        for(int i = 1; i <= n; i++){
            cout << threat[i] << (i==n?'\n':' ');
        }
    }

    return 0;
}
