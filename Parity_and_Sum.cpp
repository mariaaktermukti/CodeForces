#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> evens;
        long long s = -1;

        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (x % 2 == 0)
                evens.push_back(x);
            else
                s = max(s, x);
        }
        if (s == -1 || evens.empty()) {
            cout << 0 << "\n";
            continue;
        }

        sort(evens.begin(), evens.end());
        bool needs_extra = false;

        for (long long x : evens) {
            if (x < s) {
                s += x;         
            } else {
                needs_extra = true;  
                break;
            }
        }

        int ans = evens.size() + (needs_extra ? 1 : 0);
        cout << ans << "\n";
    }

    return 0;
}
