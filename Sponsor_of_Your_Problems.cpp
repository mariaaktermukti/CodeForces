#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 2 * l.size() << '\n';
            continue;
        }
        int ptr = 0;
        while (ptr < l.size() && l[ptr] == r[ptr]) ptr++;
        if (l[ptr] + 1 < r[ptr]) {
            cout << 2 * ptr << '\n';
        } else {
            int res = 2 * ptr + 1;
            for (int i = ptr + 1; i < l.size(); i++) {
                if (l[i] == '9' && r[i] == '0') res++;
                else break;
            }
            cout << res << '\n';
        }
    }
    return 0;
}