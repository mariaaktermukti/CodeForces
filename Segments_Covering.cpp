#include <bits/stdc++.h>
 
using namespace std;
 
using pt = pair<int, int>;
 
const int MOD = 998244353;
 
int add(int x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
   if (x < 0) x += MOD;
   return x;
}
 
int mul(int x, int y) {
  return x * 1LL * y % MOD;
}
 
int binpow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
 
int divide(int x, int y) {
  return mul(x, binpow(y, MOD - 2));
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pt>> a(m + 1);
  for (int i = 0; i < n; ++i) {
    int l, r, p, q;
    cin >> l >> r >> p >> q;
    a[r].emplace_back(l - 1, divide(p, q));
  }
  vector<int> pr(m + 1);
  pr[0] = 1;
  for (int i = 1; i <= m; ++i) {
    int cur = 1;
    for (auto [_, p] : a[i]) cur = mul(cur, add(1, -p));
    pr[i] = mul(pr[i - 1], cur);
  }
  vector<int> dp(m + 1);
  dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (auto [l, p] : a[i]) { 
      int cur = divide(pr[i], pr[l]);
      cur = divide(cur, add(1, -p));
      cur = mul(cur, p);
      dp[i] = add(dp[i], mul(dp[l], cur));
    }
  }
  cout << dp[m] << endl;  
}