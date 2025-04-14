#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        int left_steps = m / 2;
        int right_steps = m - left_steps;

        int l_prime = max(l, 0 - left_steps);
        int r_prime = l_prime + m;

        if (r_prime > r) {
            r_prime = r;
            l_prime = r_prime - m;
        }

        cout << l_prime << " " << r_prime << "\n";
    }

    return 0;
}
