#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), dp(n + 1, 0);
        vector<deque<int>> q(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            q[a[i]].push_back(i);

            if ((int)q[a[i]].size() > a[i])
                q[a[i]].pop_front();

            if ((int)q[a[i]].size() == a[i])
            {
                int start = q[a[i]].front();
                dp[i] = max(dp[i], dp[start - 1] + a[i]);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
