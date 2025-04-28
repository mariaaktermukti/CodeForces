#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll total_sum = 0;
        int operations = 0;
        bool in_negative_segment = false;

        for (int i = 0; i < n; ++i) {
            total_sum += abs(a[i]);
            if (a[i] < 0) {
                if (!in_negative_segment) {
                    operations++;
                    in_negative_segment = true;
                }
            } else if (a[i] > 0) {
                in_negative_segment = false;
            }
        }

        cout << total_sum << " " << operations << '\n';
    }
    return 0;
}
