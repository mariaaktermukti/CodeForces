#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> tops; 

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        auto it = upper_bound(tops.begin(), tops.end(), k);
        if (it == tops.end()) {
            tops.push_back(k);
        } else {
            *it = k;
        }
    }

    cout << tops.size() << "\n";
    return 0;
}
