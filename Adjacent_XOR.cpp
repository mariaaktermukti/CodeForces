#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() 
{
    int T;
    if (!(cin >> T)) return 0;
    while (T--) 
    {
        int n;
        cin >> n;
        vector<int64> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        bool ok = true;
        for (int i = 0; i < n; ++i) 
        {
            if (a[i] == b[i]) continue;
            if (i + 1 < n && ( (a[i] ^ a[i+1]) == b[i] )) continue;
            if (i + 1 < n && ( (a[i] ^ b[i+1]) == b[i] )) continue;
            ok = false;
            break;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
