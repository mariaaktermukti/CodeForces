#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  
    while (t--) {
        int n, x;
        cin >> n >> x;  
        
        vector<int> result;
        int current_or = 0;

        for (int i = 0; i < n; i++) {
            if ((current_or | i) <= x) {  
                result.push_back(i);
                current_or |= i;
            }
            if (current_or == x) { 
                result.resize(n, 0);  
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
