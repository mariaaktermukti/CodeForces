#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        long long s;
        cin >> n >> s;
        long long count = 0;
        while (n--) 
        {
            int dx, dy;
            long long x, y;
            cin >> dx >> dy >> x >> y;
            long long v = dx * x - dy * y;
            if ((v % s + s) % s == 0) 
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
