#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long t1 = llabs(a - 1);
        long long t2 = llabs(b - c) + llabs(c - 1);

        if (t1 < t2) {
            cout << 1 << "\n";
        } else if (t2 < t1) {
            cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }

    return 0;
}

