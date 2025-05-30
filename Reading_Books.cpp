#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        sum += t;
        mx = max(mx, t);
    }
    cout << max(sum, 2 * mx) << "\n";
    return 0;
}
