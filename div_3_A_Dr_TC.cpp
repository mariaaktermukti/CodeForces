#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        string s;
        cin >> n >> s;

        int cnt1 = 0;
        for (char c : s)
            if (c == '1') 
                ++cnt1;
        int cnt0 = n - cnt1;
        long long ans = 1LL * cnt1 * (n - 1) + cnt0;
        cout << ans << "\n";
    }
    return 0;
}
