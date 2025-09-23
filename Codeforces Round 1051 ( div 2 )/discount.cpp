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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(k);
        for (int i = 0; i < k; i++)
            cin >> b[i];

        sort(a.rbegin(), a.rend());

        sort(b.begin(), b.end());

        long long totalCost = 0;
        int index = 0;

        for (int i = 0; i < k; i++)
        {
            if (index + b[i] > n)
                break;
            for (int j = 0; j < b[i] - 1; j++)
            {
                totalCost += a[index + j];
            }
            index += b[i];
        }

        while (index < n)
        {
            totalCost += a[index++];
        }

        cout << totalCost << "\n";
    }
    return 0;
}
