#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; 
    }

    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        long long target2 = x - arr[i].first;
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            long long sum2 = arr[l].first + arr[r].first;
            if (sum2 == target2) {
                int i1 = arr[i].second;
                int i2 = arr[l].second;
                int i3 = arr[r].second;
                vector<int> ans = { i1, i2, i3 };
                sort(ans.begin(), ans.end());
                cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
                return 0;
            } 
            else if (sum2 < target2) {
                l++;
            } 
            else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
