#include <bits/stdc++.h>
using namespace std;

bool valid(int x, int y)
{
    return max(x, y) <= 2 * min(x, y) + 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x1 = a, y1 = b;
        int x2 = c - a, y2 = d - b;

        if (valid(x1, y1) && valid(x2, y2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
