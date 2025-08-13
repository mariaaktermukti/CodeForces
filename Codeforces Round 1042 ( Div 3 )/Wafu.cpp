#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
vector<long long> dp(31);

void precompute() {
    dp[0] = 1;
    for (int i = 1; i <= 30; i++) {
        dp[i] = i + 1;
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] * dp[j]) % MOD;
        }
    }
}

long long dfs(int v, long long k) {
    if (k == 0) return 1;
    long long ans = v + 1;
    v = min(v - 1, 30);
    k--;
    for (int j = 0; j <= v; j++) {
        if (k >= (1LL << j)) {
            ans = (ans * dp[j]) % MOD;
            k -= (1LL << j);
        } else {
            ans = (ans * dfs(j, k)) % MOD;
            break;
        }
    }
    return ans;
}

int main() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            s[i]--; 
        }
        sort(s.begin(), s.end());

        long long ans = 1;
        for (int v : s) {
            if (v <= 30 && k >= (1LL << v)) {
                k -= (1LL << v);
                ans = (ans * dp[v]) % MOD;
            } else {
                ans = (ans * dfs(v, k)) % MOD;
                break;
            }
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
