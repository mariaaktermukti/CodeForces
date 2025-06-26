#include<bits/stdc++.h>

using namespace std;

const int N = 543;
const long long INF64 = (long long)(1e18);

long long e[N][N];
long long d[N][N];
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j) e[i][j] = INF64;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        --x;
        --y;
        swap(x, y);
        e[x][y] = min(e[x][y], (long long)w);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = e[i][j];
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        long long op;
        cin >> op;
        vector<long long> a(n);
        for(int j = 0; j < n; j++) cin >> a[j];
        vector<long long> min_dist = a;
        vector<long long> min_one_edge = a;
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                min_dist[k] = min(min_dist[k], a[j] + d[j][k]);
                min_one_edge[k] = min(min_one_edge[k], a[j] + e[j][k]);
            }
        vector<long long> min_op(n, INF64);
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                if(d[j][k] < e[j][k]) min_op[k] = min(min_op[k], (d[j][k] + a[j]) - (min_one_edge[k] - 1));
            }               
        for(int j = 0; j < n; j++)
        {
            if(min_op[j] <= op) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    return 0;
}