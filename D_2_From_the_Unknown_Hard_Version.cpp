#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        // Construct first query: words of length 1..N until sum <= 25000
        vector<int> query;
        int sum = 0, val = 1;
        while(sum + val <= 25000) {
            query.push_back(val);
            sum += val;
            val++;
        }

        // First query
        cout << "? " << query.size();
        for(int x : query) cout << " " << x;
        cout << endl;
        cout.flush();

        int lines;
        cin >> lines;
        if(lines == -1) return 0;

        // Compute W_guess = ceil(total_sum / lines)
        int total_sum = accumulate(query.begin(), query.end(), 0);
        int W_guess = (total_sum + lines - 1) / lines;

        // Second query: check W_guess
        cout << "? 1 " << W_guess << endl;
        cout.flush();

        int resp;
        cin >> resp;
        if(resp == -1) return 0;

        if(resp == 0) W_guess--; // cannot fit → W smaller

        cout << "! " << W_guess << endl;
        cout.flush();
    }
}
