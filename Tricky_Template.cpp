#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] != c[i] && b[i] != c[i]) 
            {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
