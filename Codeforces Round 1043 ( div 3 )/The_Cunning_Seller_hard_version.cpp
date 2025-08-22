#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> cost;
    long long c = 3;
    long long cnt = 1;
    for (int i = 0; i < 21; ++i)
    {
        cost.push_back(c);
        c = 3 * c + cnt;
        cnt *= 3;
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> tr;
        long long min_k = 0;
        while (n)
        {
            tr.push_back(n % 3);
            min_k += n % 3;
            n /= 3;
        }
        if (min_k > k)
        {
            cout << -1 << '\n';
            continue;
        }
        k -= min_k;
        k /= 2;
        for (int i = (int)tr.size() - 1; i >= 1; --i)
        {
            if (tr[i] <= k)
            {
                tr[i - 1] += 3 * tr[i];
                k -= tr[i];
                tr[i] = 0;
            }
            else
            {
                tr[i - 1] += k * 3;
                tr[i] -= k;
                break;
            }
        }
        long long an = 0;
        for (int i = (int)tr.size() - 1; i >= 0; --i)
            an += cost[i] * tr[i];
        cout << an << '\n';
    }
    return 0;
}
