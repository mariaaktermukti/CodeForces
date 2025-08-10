#include <bits/stdc++.h>
using namespace std;
map<long long,int> mS, mT;

bool checking(map<long long,int>::iterator it, map<long long,int>::iterator itT) {
    if (it == mS.end() && itT == mT.end()) return true;
    if (it == mS.end() || itT == mT.end()) return false;
    if (it->first != itT->first || it->second != itT->second) return false;
    return checking(next(it), next(itT));
}

int main() 
{
    int t;
    if (!(cin >> t)) 
    {
        return 0;
    }
    while (t--) 
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> S(n), T(n);
        for (auto &x : S) 
        {
            cin >> x;
        }
        for (auto &x : T) 
        {
            cin >> x;
        }
        if (k == 0) 
        {
            sort(S.begin(), S.end());
            sort(T.begin(), T.end());
            cout << (S == T ? "YES\n" : "NO\n");
            continue;
        }

        mS.clear();
        mT.clear();

        for (auto x : S) 
        {
            long long r = x % k;
            long long key = min(r, (k - r) % k);
            mS[key]++;
        }
        for (auto x : T) 
        {
            long long r = x % k;
            long long key = min(r, (k - r) % k);
            mT[key]++;
        }

        if (mS.size() != mT.size()) 
        {
            cout << "NO\n";
            continue;
        }

        cout << (checking(mS.begin(), mT.begin()) ? "YES\n" : "NO\n");
    }
    return 0;
}
