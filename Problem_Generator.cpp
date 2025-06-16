#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        long long n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        long long ans = 0;
        for (char c = 'A'; c < 'H'; ++c) 
        {
            long long cnt = count(a.begin(), a.end(), c);
            ans += max(0LL, m - cnt);
        }

        cout << ans << "\n";
    }

    return 0;
}
