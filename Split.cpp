#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    vector<int> freq(2 * n + 1, 0);
    for (int x : a)
        freq[x]++;

    int odd = 0;
    int mod2 = 0;
    int mod0 = 0;

    for (int i = 1; i <= 2 * n; i++)
    {
        if (freq[i] == 0)
            continue;

        if (freq[i] % 2 == 1)
            odd++;
        else if (freq[i] % 4 == 2)
            mod2++;
        else
            mod0++;
    }

    int answer = odd + 2 * mod2 + 2 * mod0;

    if (odd == 0 && mod0 % 2 == 1)
    {
        answer -= 2;
    }

    cout << answer << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
