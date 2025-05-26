#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = stoi(s);
        
        int r = static_cast<int>(sqrt(n));
        while ((long long)(r + 1) * (r + 1) <= n) r++;
        while ((long long)r * r > n) r--;

        if ((long long)r * r != n) {
            cout << -1;
        } else {
            int a0 = stoi(s.substr(0, 2));
            int b0 = stoi(s.substr(2, 2));
            if (a0 + b0 == r) {
                cout << a0 << " " << b0;
            } else {
                int half = r / 2;
                bool printed = false;
                for (int a = half; a >= 0; --a) {
                    int b = r - a;
                    if (a != b) {
                        cout << a << " " << b;
                        printed = true;
                        break;
                    }
                }
                if (!printed) cout << 0 << " " << r;
            }
        }
        if (t) cout << '\n';
    }
    return 0;
}