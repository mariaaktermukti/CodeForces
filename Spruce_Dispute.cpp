#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int S = 200005;

using ll = long long;

ll coloring[S], centroid, best, best_dist, n, color;
vector<vector<ll>> g;

ll search_centroid(ll u, ll from) {
    ll sum = 0;
    bool is_centroid = true;

    for (ll v : g[u]) {
        if (v != from) {
            ll subtree_size = search_centroid(v, u);
            if (subtree_size > n / 2) is_centroid = false;
            sum += subtree_size;
        }
    }

    if (is_centroid && n - 1 - sum <= n / 2) {
        centroid = u;
    }

    return sum + 1;
}

void make_coloring(ll u, ll from, ll dist) {
    coloring[u] = (color++) % (n / 2) + 1;

    if (g[u].size() == 1 && dist < best_dist) {
        best_dist = dist;
        best = u;
    }

    for (ll v : g[u]) {
        if (v != from) {
            make_coloring(v, u, dist + 1);
        }
    }
}

void solve() {
    centroid = -1;
    best_dist = S;
    color = 0;

    cin >> n;
    g.assign(n, vector<ll>());

    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    search_centroid(1543 % n, -1);
    make_coloring(centroid, -1, 0);

    ll bbest = max(best, g[best][0]);

    coloring[centroid] = coloring[bbest];
    coloring[bbest] = 0;

    cout << best + 1 << " " << g[best][0] + 1 << "\n";

    for (ll i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << coloring[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc;
    cin >> tc;
    while (tc--) solve();

    return 0;
}
