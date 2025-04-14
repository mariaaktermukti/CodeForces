#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAXA = 100000;

// smallest-prime-factor sieve
int spf[MAXA+1];

// build spf[]
void build_sieve(){
    for(int i = 2; i <= MAXA; i++){
        if(!spf[i]){
            for(int j = i; j <= MAXA; j += i){
                if(!spf[j]) spf[j] = i;
            }
        }
    }
}

// factorize x <= MAXA in O(log x)
vector<pair<int,int>> factorize(int x){
    vector<pair<int,int>> fac;
    while(x > 1){
        int p = spf[x], cnt = 0;
        while(x % p == 0){
            x /= p;
            cnt++;
        }
        fac.emplace_back(p, cnt);
    }
    return fac;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve();

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // nextPos[i][p] = smallest j>i such that p | a[j], or n+1 if none
        vector<unordered_map<int,int>> nextPos(n+2);
        unordered_map<int,int> last;  // last occurrence of prime p

        // initialize beyond-end to n+1
        for(auto &mp : nextPos) mp.reserve(4);

        // scan right-to-left
        for(int i = n; i >= 1; i--){
            nextPos[i] = nextPos[i+1];
            int x = a[i];
            while(x > 1){
                int p = spf[x];
                nextPos[i][p] = (last.count(p) ? last[p] : n+1);
                last[p] = i;
                while(x % p == 0) x /= p;
            }
        }

        while(q--){
            int k, l, r;
            cin >> k >> l >> r;
            auto kfac = factorize(k);
            vector<int> breakpoints;
            breakpoints.reserve(16);

            for(auto &pe : kfac){
                int p = pe.first, e = pe.second;
                int pos = l;
                for(int cnt = 0; cnt < e; cnt++){
                    pos = nextPos[pos].count(p) ? nextPos[pos][p] : n+1;
                    if(pos > r) break;
                }
                breakpoints.push_back(min(pos, r+1));
            }
            sort(breakpoints.begin(), breakpoints.end());
            ll ans = 0;
            ll currK = k;
            int prev = l;

            for(int bp : breakpoints){
                if(prev > r) break;
                int upTo = min(bp, r+1);
                ans += currK * (upTo - prev);
                if(bp <= r){
                    for(auto &pe : kfac){
                        int p = pe.first;
                        if(bp == *lower_bound(
                                    breakpoints.begin(),
                                    breakpoints.end(),
                                    bp
                                )){
                            if(currK % p == 0){
                                currK /= p;
                                break;
                            }
                        }
                    }
                }
                prev = upTo;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
