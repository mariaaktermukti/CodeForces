#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;  
    
    while (t--) {
        int n;
        cin >> n; 
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }
    
        sort(a.rbegin(), a.rend());
    
        while (a.size() > 1) {
            int x = a[0] + a[1];
            a[1] = x; 
            a.erase(a.begin());  
        
            sort(a.rbegin(), a.rend());
        }
        cout << a[0] << endl;
    }
    
    return 0;
}
