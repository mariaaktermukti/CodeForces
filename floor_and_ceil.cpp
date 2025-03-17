#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;  // Read x, n, and m

        int max_x = x, min_x = x;

        // Maximize x by performing m ceil operations first
        while (m--) {
            max_x = (max_x + 1) / 2;  // Ceil operation
        }

        // Minimize x by performing n floor operations first
        while (n--) {
            min_x = min_x / 2;  // Floor operation
        }

        // Output the minimum and maximum possible values of x
        cout << min_x << " " << max_x << endl;
    }

    return 0;
}
