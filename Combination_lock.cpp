#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0 && n != 1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            long long val = (2LL * i) % n; 
            cout << val + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
