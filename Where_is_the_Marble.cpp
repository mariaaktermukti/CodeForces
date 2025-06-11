#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q, caseNo = 1;
    while (cin >> N >> Q && (N || Q)) {
        vector<int> marbles(N);
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNo++ << ":\n";

        while (Q--) {
            int query;
            cin >> query;
            auto it = lower_bound(marbles.begin(), marbles.end(), query);
            if (it != marbles.end() && *it == query) {
                cout << query << " found at " << (it - marbles.begin() + 1) << endl;
            } else {
                cout << query << " not found" << endl;
            }
        }
    }
    return 0;
}
