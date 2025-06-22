#include <iostream>
 
using namespace std;
 
void solve() {
    long long n, m, k, l, r, mid;
    cin >> n >> m >> k;
    l = 0, r = m;
    
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if ((m / (mid + 1) * mid + m % (mid + 1)) * n >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    
    cout << r << endl;
} 
 
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
