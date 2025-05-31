#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> P(n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + a[i - 1];
    }

    vector<long long> all;
    all.reserve(2 * (n + 1));
    for (int i = 0; i <= n; i++) {
        all.push_back(P[i]);
        all.push_back(P[i] - x);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int M = (int)all.size();
    vector<int> compP(n + 1), compT(n + 1);
    for (int i = 0; i <= n; i++) {
        compP[i] = int(lower_bound(all.begin(), all.end(), P[i]) - all.begin());
        compT[i] = int(lower_bound(all.begin(), all.end(), P[i] - x) - all.begin());
    }

    vector<int> freq(M, 0);
    long long answer = 0;

    freq[compP[0]] = 1;

    for (int i = 1; i <= n; i++) {
        answer += freq[compT[i]];
        freq[compP[i]]++;
    }

    cout << answer << "\n";
    return 0;
}
