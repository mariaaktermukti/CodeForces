#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int h, n; cin >> h >> n;
		vector<int> a(n), c(n);
		for(int& i: a) cin >> i;
		for(int& i: c) cin >> i;
		set<pair<long long, int>> S;
		for(int i = 0; i < n; i++){
			S.insert({1, i});
		}
		long long last_turn = 1;
		while(h > 0){
			auto [turn, i] = *S.begin();
			S.erase(S.begin());
			last_turn = turn;
			h -= a[i];
			S.insert({turn + c[i], i});
		}
		cout << last_turn << "\n";
	}
}