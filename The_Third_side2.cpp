#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sumA = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            sumA += x;
        }
        long long answer = sumA - (n - 1);
        cout << answer << "\n";
    }
    return 0;
}
