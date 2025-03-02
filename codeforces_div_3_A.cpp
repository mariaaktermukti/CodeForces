#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    
    int max_sum = n * p;

    int min_sum = n * (-p);
    
  
    if (k < min_sum || k > max_sum) {
        cout << -1 << "\n";
        return;
    }

    int required_sum = abs(k);
    int min_operations = (required_sum + p - 1) / p; 
    
    cout << min_operations << "\n";
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
