#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    const int MAXD = 60;
    const int MAXK = MAXD;
    const unsigned long long INF = ULLONG_MAX/2;

    vector<vector<unsigned long long>> dp(MAXD+1, vector<unsigned long long>(MAXD+1, INF));
    dp[0][0] = 0;

    for (int k = 1; k <= MAXK; k++){
        vector<vector<unsigned long long>> newdp(MAXD+1, vector<unsigned long long>(MAXD+1, INF));
        for (int i = 0; i <= MAXD; i++){
            for (int j = 0; j <= MAXD; j++){
                unsigned long long cur = dp[i][j];
                if(cur == INF) continue;
                if(cur < newdp[i][j])
                    newdp[i][j] = cur;
                if(i + k <= MAXD){
                    unsigned long long candidate = cur + (1ULL << k);
                    if(candidate < newdp[i+k][j])
                        newdp[i+k][j] = candidate;
                }
                if(j + k <= MAXD){
                    unsigned long long candidate = cur + (1ULL << k);
                    if(candidate < newdp[i][j+k])
                        newdp[i][j+k] = candidate;
                }
            }
        }
        dp = move(newdp);
    }
 
    struct Entry { int dx, dy; unsigned long long cost; };
    vector<Entry> vec;
    for (int i = 0; i <= MAXD; i++){
        for (int j = 0; j <= MAXD; j++){
            if(dp[i][j] < INF){
                vec.push_back({i, j, dp[i][j]});
            }
        }
    }
    sort(vec.begin(), vec.end(), [](const Entry &a, const Entry &b){
        return a.cost < b.cost;
    });

    int t; 
    cin >> t;
    while(t--){
        unsigned long long x, y;
        cin >> x >> y;
        if(x == y){
            cout << 0 << "\n";
            continue;
        }

        unsigned long long X[MAXD+1], Y_arr[MAXD+1];
        for (int d = 0; d <= MAXD; d++){
            X[d] = x >> d;
            Y_arr[d] = y >> d; 
        }
        unsigned long long ans = ULLONG_MAX;
        for (auto &entry : vec){
            int dx = entry.dx, dy = entry.dy;
            if(X[dx] == Y_arr[dy]){
                if(entry.cost < ans)
                    ans = entry.cost;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
