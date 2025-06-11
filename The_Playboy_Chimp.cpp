#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m;
    cin >> m;
    while (m--) {
        long long x;
        cin >> x;
        long long ans1 = -1, ans2 = -1;

        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] < x) {
                ans1 = a[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        l = 0, r = n - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] > x) {
                ans2 = a[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ans1 == -1)
            cout << "X ";
        else
            cout << ans1 << " ";

        if (ans2 == -1)
            cout << "X\n";
        else
            cout << ans2 << "\n";
    }

    return 0;
}
