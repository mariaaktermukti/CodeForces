#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void zihad_solve()
{
    int n;
    cin >> n;
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = (1LL * result % MOD * i % MOD) % MOD;
    }
    cout << result<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        zihad_solve();
    }
    return 0;
}