#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }

        bool is_beautiful = false;
        for (int i = 0; i + 1 < n; i++) 
        {
            if (llabs(a[i] - a[i + 1]) <= 1) 
            {
                is_beautiful = true;
                break;
            }
        }
        if (is_beautiful) {
            cout << 0 << endl;
            continue;
        }

        bool can_beautiful = false;
        for (int i = 0; i + 1 < n; i++) 
        {
            long long u = a[i], v = a[i + 1];
            long long lo = min(u, v), hi = max(u, v);
            if (i - 1 >= 0) 
            {
                long long L = a[i - 1];
                long long left_lo = max(lo, L - 1);
                long long left_hi = min(hi, L + 1);
                if (left_lo <= left_hi) 
                {
                    can_beautiful = true;
                    break;
                }
            }
            if (i + 2 < n) 
            {
                long long R = a[i + 2];
                long long right_lo = max(lo, R - 1);
                long long right_hi = min(hi, R + 1);
                if (right_lo <= right_hi) 
                {
                    can_beautiful = true;
                    break;
                }
            }
        }

        if (n >= 3 && can_beautiful) 
        {
            cout << 1 << endl;
        } 
        else 
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
