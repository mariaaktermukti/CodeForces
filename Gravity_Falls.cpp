#include <bits/stdc++.h>
using namespace std;

bool lexCompare(const vector<int> &a, const vector<int> &b)
{
    int n = a.size(), m = b.size();
    for (int i = 0; i < min(n, m); i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return n < m;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arrays(n);
        int max_len = 0;

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            arrays[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> arrays[i][j];
            }
            max_len = max(max_len, k);
        }

        vector<int> bottomRow;

        for (int i = 0; i < max_len;)
        {
            vector<int> bestSuffix;
            int bestIndex = -1;

            for (int j = 0; j < n; j++)
            {
                if (arrays[j].size() > i)
                {
                    vector<int> suffix(arrays[j].begin() + i, arrays[j].end());
                    if (bestIndex == -1 || lexCompare(suffix, bestSuffix))
                    {
                        bestSuffix = suffix;
                        bestIndex = j;
                    }
                }
            }

            for (int val : bestSuffix)
                bottomRow.push_back(val);

            i = bottomRow.size();
        }

        for (int x : bottomRow)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
