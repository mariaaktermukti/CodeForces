#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int count_dash = count(s.begin(), s.end(), '-');
    int count_underscore = count(s.begin(), s.end(), '_');
    
    if (count_dash == 0 || count_underscore == 0 || n < 3) {
        cout << 0 << "\n";
        return;
    }
    
    long long max_subsequences = 1LL * count_dash * (count_dash - 1) / 2 * count_underscore;
    cout << max_subsequences << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
