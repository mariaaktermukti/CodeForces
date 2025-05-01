#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        long long a, b, n, S;
        cin >> a >> b >> n >> S;

        long long use_n = min(a, S / n);
        long long rem = S - use_n * n;

        if (rem <= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
