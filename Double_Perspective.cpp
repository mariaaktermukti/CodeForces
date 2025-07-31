#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p;
    DSU(int _n): n(_n), p(n+1, -1) {}
    int find(int x) 
    {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) 
    {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a,b);
        p[a] += p[b];
        p[b] = a;
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<tuple<int,int,int,int>> edges;
        edges.reserve(n);
        for (int i = 1; i <= n; i++) 
        {
            int a, b;
            cin >> a >> b;
            edges.emplace_back(b - a, a, b, i);
        }
        sort(edges.begin(), edges.end(),
             [&](auto &L, auto &R){
                 return get<0>(L) > get<0>(R);
             });
        DSU dsu(2*n);
        vector<int> answer;
        answer.reserve(n);

        for (auto &e : edges) 
        {
            int w = get<0>(e);
            int a = get<1>(e);
            int b = get<2>(e);
            int idx = get<3>(e);
            if (dsu.unite(a, b)) 
            {
                answer.push_back(idx);
            }
        }
        cout << answer.size() << "\n";
        for (int idx : answer) 
        {
            cout << idx << " ";
        }
        cout << "\n";
    }
    return 0;
}
