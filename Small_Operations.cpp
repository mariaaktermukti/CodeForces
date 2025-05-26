#include <bits/stdc++.h>
using namespace std;

static vector<int> tempExp;

static vector<pair<int,int>> factor(int n) {
    vector<pair<int,int>> res;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                ++cnt;
            }
            res.emplace_back(p, cnt);
        }
    }
    if (n > 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

static void genSmooth(int idx,
                      long long curVal,
                      const vector<int>& primes,
                      const vector<int>& maxExp,
                      int k,
                      vector<vector<int>>& outExps)
{
    if (idx == (int)primes.size()) {
        outExps.push_back(tempExp);
        return;
    }
    int p = primes[idx];
    long long v = curVal;
    for (int e = 0; e <= maxExp[idx]; ++e) {
        tempExp[idx] = e;
        genSmooth(idx + 1, v, primes, maxExp, k, outExps);
        if (v > k / p) break; 
        v *= p;
    }
}

static int solveCase(int x, int y, int k) {
    if (x == y) return 0;

    auto fx = factor(x);
    auto fy = factor(y);

    map<int,int> mp;
    for (auto &pr : fx) mp[pr.first] = max(mp[pr.first], pr.second);
    for (auto &pr : fy) mp[pr.first] = max(mp[pr.first], pr.second);

    vector<int> primes, maxExp;
    for (auto &pr : mp) {
        primes.push_back(pr.first);
        maxExp.push_back(pr.second);
    }
    int m = primes.size();

    vector<int> start(m, 0), target(m, 0);
    for (int i = 0; i < m; ++i) {
        int p = primes[i];
        for (auto &pr : fx) if (pr.first == p) start[i] = pr.second;
        for (auto &pr : fy) if (pr.first == p) target[i] = pr.second;
    }

    tempExp.assign(m, 0);
    vector<vector<int>> smoothExps;
    genSmooth(0, 1LL, primes, maxExp, k, smoothExps);

    vector<int> limit(m);
    for (int i = 0; i < m; ++i) {
        limit[i] = max(start[i], target[i]) + 5;
    }

    vector<int> stride(m, 1);
    for (int i = 1; i < m; ++i) {
        stride[i] = stride[i-1] * (limit[i-1] + 1);
    }
    int totalStates = stride[m-1] * (limit[m-1] + 1);

    auto encode = [&](const vector<int>& v){
        int h = 0;
        for (int i = 0; i < m; ++i) {
            h += v[i] * stride[i];
        }
        return h;
    };

    vector<int> dist(totalStates, -1);
    queue<vector<int>> q;

    int h0 = encode(start);
    dist[h0] = 0;
    q.push(start);

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cd = dist[encode(cur)];
        for (auto &dexp : smoothExps) {
            vector<int> nxt(m);
            bool good = true;
            for (int i = 0; i < m; ++i) {
                int nv = cur[i] + dexp[i];
                if (nv < 0 || nv > limit[i]) { good = false; break; }
                nxt[i] = nv;
            }
            if (good) {
                int h = encode(nxt);
                if (dist[h] < 0) {
                    dist[h] = cd + 1;
                    if (nxt == target) return dist[h];
                    q.push(nxt);
                }
            }
            good = true;
            for (int i = 0; i < m; ++i) {
                if (cur[i] < dexp[i]) { good = false; break; }
            }
            if (good) {
                for (int i = 0; i < m; ++i) {
                    nxt[i] = cur[i] - dexp[i];
                }
                int h = encode(nxt);
                if (dist[h] < 0) {
                    dist[h] = cd + 1;
                    if (nxt == target) return dist[h];
                    q.push(nxt);
                }
            }
        }
    }

    return -1;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << solveCase(x, y, k) << "\n";
    }
}
