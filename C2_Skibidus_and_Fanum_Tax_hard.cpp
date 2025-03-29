#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int j = 0; j < m; j++){
            cin >> b[j];
        }
        sort(b.begin(), b.end());
        long long prev = -1LL << 60; 

        bool possible = true;
        for(int i = 0; i < n; i++){
            long long candidate = LLONG_MAX;
            if(a[i] >= prev){
                candidate = min(candidate, a[i]);
            }
            long long needed = prev + a[i];
            auto it = lower_bound(b.begin(), b.end(), needed);
            if(it != b.end()){
                long long x = (*it) - a[i];
                if(x >= prev){
                    candidate = min(candidate, x);
                }
            }

            if(candidate == LLONG_MAX){
                possible = false;
                break;
            }
            prev = candidate;
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
