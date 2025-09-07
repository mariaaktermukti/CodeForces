#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n = 25000; // max allowed sum of lengths
        cout << "? " << n;
        for(int i = 0; i < n; i++) cout << " 1";
        cout << endl;
        cout.flush();

        int lines;
        cin >> lines;
        if(lines == -1) return 0;

        // Calculate W range
        int W_min = (n + lines - 1) / lines; // ceil
        int W_max = (lines == 1) ? 1e5 : n / (lines - 1); // if lines>1

        // Second query: check W_max
        cout << "? 1 " << W_max << endl;
        cout.flush();

        int resp;
        cin >> resp;
        if(resp == -1) return 0;

        int W = (resp == 1) ? W_max : W_min;

        cout << "! " << W << endl;
        cout.flush();
    }
}
