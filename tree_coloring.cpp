#include <bits/stdc++.h>
 
using namespace std;

const int M = 5e5;
const int INF = 1e9;

int main() 
{
  vector<int> dp(M + 1, INF);
  dp[1] = 1;
  for (int m = 2; m <= M; ++m) 
  {
    for (int i = 1; i * i <= m; ++i) 
    {
      if (m % i != 0) continue;
      if (m / i > 2) dp[m] = min(dp[m], dp[i] + dp[m / i - 2]);
      if (i > 2) dp[m] = min(dp[m], dp[m / i] + dp[i - 2]);
    }
  }
  
  int q;
  cin >> q;
  while (q--) 
  {
    int m;
    cin >> m;
    cout << (dp[m] == INF ? -1 : dp[m]) << '\n';
  }
}