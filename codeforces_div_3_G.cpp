#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    unsigned int k;
    cin >> n >> k;
    
    vector<unsigned int> row(n, 0);
    row[0] = k;
    row[n - 1] = k;
    
    for (int i = 0; i < n; ++i) {
        cout << row[i] << " ";
    }
    cout << "\n";
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
