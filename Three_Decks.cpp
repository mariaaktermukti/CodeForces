#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if ((a + b + c) % 3 != 0) {
            cout << "NO" << endl;
            continue;
        }

        int x = (a + b + c) / 3;

        if (b <= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
