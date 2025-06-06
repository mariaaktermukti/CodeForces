#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), prefix(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix[i] = a[i] + (i > 0 ? prefix[i - 1] : 0);
    }

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        int idx = lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
        cout << idx + 1 << endl;
    }

    return 0;
}
