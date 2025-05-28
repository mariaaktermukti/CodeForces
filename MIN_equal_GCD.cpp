#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<ll> a(n);
		for (ll &x : a) {
			cin >> x;
		}
		int p = min_element(a.begin(), a.end()) - a.begin();
		ll g = 0;
		for (int i = 0; i < n; ++i) {
			if (i != p && a[i] % a[p] == 0) {
				g = __gcd(g, a[i]);
			}
		}
		cout << (g == a[p] ? "Yes\n" : "No\n");
	}
	return 0;
}