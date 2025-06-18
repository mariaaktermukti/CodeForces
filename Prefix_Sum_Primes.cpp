#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ones = 0, twos = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) ones++;
        else twos++;
    }

    int maxS = 2*n + 5;
    vector<bool> isPrime(maxS, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i < maxS; i++){
        if(isPrime[i]){
            for(int j = i*i; j < maxS; j += i)
                isPrime[j] = false;
        }
    }
    
    vector<int> ans;
    ans.reserve(n);
    int cur = 0;

    while(ones > 0 || twos > 0){
        if(ones > 0 && isPrime[cur + 1]){
            ans.push_back(1);
            cur += 1;
            ones--;
        }
        else if(twos > 0 && isPrime[cur + 2]){
            ans.push_back(2);
            cur += 2;
            twos--;
        }
        else break;
    }
    while(ones-- > 0) ans.push_back(1);
    while(twos-- > 0) ans.push_back(2);

    for(int i = 0; i < n; i++){
        cout << ans[i] << (i+1<n?' ':'\n');
    }
    return 0;
}
