#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                ans += (cnt + 1) / (k + 1);
                cnt = 0;
                continue;
            }
            else
            {
                cnt++;
            }
        }
        ans += (cnt + 1) / (k + 1);
        cout << ans << endl;
    }
}