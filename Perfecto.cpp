#include<bits/stdc++.h>
using namespace std;
void solve() 
{
    auto check = [&](int k) 
    {
        int j = sqrtl((int64_t)k * (k + 1) / 2);
        return ((int64_t)j * j != (int64_t)k * (k + 1) / 2);
    };

    int n;
    cin >> n;
    if (!check(n)) 
    {
        cout << "-1\n";
        return;
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        ans[i] = i;
    }

    int j = 0;
    for (int i = 1; i <= n; i++) 
    {
        while ((int64_t)j * j < (int64_t)i * (i + 1) / 2) j++;
        if ((int64_t)j * j == (int64_t)i * (i + 1) / 2) 
        {
            swap(ans[i], ans[i + 1]);
        }
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) 
    {
        solve();
    }
}