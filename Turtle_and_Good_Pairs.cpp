#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> freq(26, 0);
        for (char c : s) 
            freq[c - 'a']++;

        vector<pair<int,char>> v;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                v.emplace_back(freq[i], char('a' + i));
        }
        sort(v.rbegin(), v.rend());

        string t(n, ' ');
        int pos = 0;
        for (auto &p : v) {
            int cnt = p.first;
            char  c   = p.second;
            while (cnt--) {
                if (pos >= n) 
                    pos = 1;
                t[pos] = c;
                pos += 2;
            }
        }
        cout << t << "\n";
    }
    return 0;
}
