#include <iostream>

using namespace std;

const int MAXN = 2010;
const int MOD = 998244353;

string s[MAXN];
int dp[MAXN][MAXN][2];
long long sdp[MAXN][MAXN][2];

int n, m, d;

long long getsum(int x, int y1, int y2, int f) 
{
    long long res = sdp[x][y2][f];
    if (y1) res -= sdp[x][y1 - 1][f];
    return res;
}

int get(int i, int j, int f) 
{
    if (s[i][j] != 'X') return 0;
    long long res = 0;
    if (i == n - 1) res++;

    if (!f) 
    {
        res += getsum(i, max(0, j - d),
                      min(m - 1, j + d), 1);
        res -= dp[i][j][1];
    }

    if (i < n - 1) 
    {
        res += getsum(i + 1, max(0, j - d + 1),
                      min(m - 1, j + d - 1), 0);
    }

    return res % MOD;
}

void solve() 
{

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) 
    {
        cin >> s[i];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int f = 1; f >= 0; f--) 
        {
            for (int j = 0; j < m; j++) 
            {
                sdp[i][j][f] = dp[i][j][f] = get(i, j, f);
            }
            for (int j = 1; j < m; j++) 
            {
                sdp[i][j][f] += sdp[i][j - 1][f];
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j < m; j++) 
    {
        ans += dp[0][j][0];
    }

    cout << ans % MOD << endl;

}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}