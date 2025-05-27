#include <bits/stdc++.h>
using namespace std;

int min_divisor(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0)
            return d;
    }
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        bool found = false;
        
        for (int x = l; x <= r; ++x) {
            int md = min_divisor(x);
            if (md != x) {
                cout << md << " " << x - md << "\n";
                found = true;
                break;
            }
        }
        
        if (!found)
            cout << -1 << "\n";
    }
    
    return 0;
}
