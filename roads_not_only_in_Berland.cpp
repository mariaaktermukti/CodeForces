#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int par[N], group_size[N], cmp;
vector<pair<int, int>> extra_edges;
vector<int> components;

int find(int node) {
    if (par[node] == -1)
        return node;
    return par[node] = find(par[node]);
}

void dsu_union(int node1, int node2) {
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 == leader2) {
        extra_edges.push_back({node1, node2}); 
        return;
    }

    if (group_size[leader1] >= group_size[leader2]) {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
    cmp--;
}

int main() {
    int n;
    cin >> n;
    cmp = n;

    for (int i = 1; i <= n; i++) {
        par[i] = -1;
        group_size[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            components.push_back(i); 
        }
    }

    int changes = components.size() - 1;
    cout << changes << endl;

    for (int i = 1; i <= changes; i++) {
        cout << extra_edges[i - 1].first << " " << extra_edges[i - 1].second << " ";
        cout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}
