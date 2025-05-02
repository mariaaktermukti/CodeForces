#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        string t;
        cin >> n >> t;

        string s;
        for (int i = n - 1; i >= 0; ) {
            if (t[i] == '0') {
                int num = (t[i-2] - '0') * 10 + (t[i-1] - '0');
                s.push_back(char('a' + num - 1));
                i -= 3;
            } else {
                int num = t[i] - '0';
                s.push_back(char('a' + num - 1));
                i -= 1;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

    return 0;
}
