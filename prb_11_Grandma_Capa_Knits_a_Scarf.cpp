#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(const string& s, char ch) {
    int l = 0, r = s.size() - 1;
    int cnt = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (s[l] == ch) {
                cnt++;
                l++;
            } else if (s[r] == ch) {
                cnt++;
                r--;
            } else {
                return 1e9; 
            }
        }
    }
    return cnt;
}

bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (isPalindrome(s)) {
            cout << 0 << '\n';
            continue;
        }

        int ans = 1e9;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            ans = min(ans, solve(s, ch));
        }

        if (ans == 1e9)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
