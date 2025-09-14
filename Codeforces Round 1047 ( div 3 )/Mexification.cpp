#include <bits/stdc++.h>
using namespace std;

vector<int> mexify(const vector<int> &a)
{
    int n = a.size();
    vector<int> freq(n + 2, 0);
    for (int x : a)
        freq[x]++;

    int mex = 0;
    while (freq[mex] > 0)
        mex++;

    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mex && freq[a[i]] == 1)
        {
            res[i] = a[i];
        }
        else
        {
            res[i] = mex;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (k == 0)
        {
            long long sum = 0;
            for (int x : a)
                sum += x;
            cout << sum << "\n";
            continue;
        }

        vector<int> b = mexify(a);
        if (k == 1)
        {
            long long sum = 0;
            for (int x : b)
                sum += x;
            cout << sum << "\n";
            continue;
        }

        vector<int> c = mexify(b);
        long long sum = 0;
        for (int x : c)
            sum += x;
        cout << sum << "\n";
    }
    return 0;
}
