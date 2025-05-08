#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int pairs = (n + 1) / 2; 
    cout << pairs << endl;

    int left = 1;
    int right = 3 * n;

    for (int i = 0; i < pairs; i++) {
        cout << left << " " << right << endl;
        left += 3;
        right -= 3;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
