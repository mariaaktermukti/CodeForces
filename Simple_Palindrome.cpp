#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    const string vowels = "aeiou";
    while (t--) {
        int n;
        cin >> n;

        int base = n / 5;
        int rem  = n % 5;
        vector<int> cnt(5, base);
        for (int i = 0; i < rem; i++) {
            cnt[i]++;
        }

        string ans;
        ans.reserve(n);
        for (int i = 0; i < 5; i++) {
            ans.append(cnt[i], vowels[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
