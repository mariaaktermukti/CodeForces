#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            q[i] = n + 1 - p[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
