#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18

vector<pair<int, int>> adj[100005]; // Adjacency list
int dist[100005]; // Shortest distances
int parent[100005]; // To store the path

void dijkstra(int start, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    fill(dist, dist + n + 1, INF); // Initialize all distances as INF
    dist[start] = 0;
    parent[start] = -1; // Starting node has no parent
    pq.push({0, start}); // (distance, node)

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue; // Skip outdated distances

        for (auto edge : adj[node]) { // Fix: No structured bindings
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                parent[neighbor] = node; // Track the path
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

void print_path(int n) {
    if (dist[n] == INF) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    for (int v : path)
        cout << v << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // Since the graph is undirected
    }

    dijkstra(1, n); // Run Dijkstra from node 1
    print_path(n);  // Print shortest path to node n

    return 0;
}
