#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long count = (n / 15) * 3;
        int remainder = n % 15;
        if (remainder >= 0) count++;  
        if (remainder >= 1) count++;  
        if (remainder >= 2) count++;  
        cout << count << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
