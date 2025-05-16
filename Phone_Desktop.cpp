#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int nt;
    cin >> nt;
    while (nt--) {
        int x, y;
        cin >> x >> y;
        int mm = (y + 1) / 2; 
        x -= (mm * 5 * 3 - y * 2 * 2);
        x = max(x, 0);
        mm += (x + 5 * 3 - 1) / (5 * 3);
        cout << mm << endl;
    }
    return 0;
}
