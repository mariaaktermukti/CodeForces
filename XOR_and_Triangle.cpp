#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(long long u) {
    return (u & (u - 1)) == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long x;
        cin >> x;

        if(isPowerOfTwo(x)){
            cout << -1 << "\n";
            continue;
        }
        if(isPowerOfTwo(x+1)){
            cout << -1 << "\n";
            continue;
        }

        
        int b = __builtin_ctzll(x); 
        long long baseY = 1LL << b;

        long long y = -1;
        for(int p = 31; p >= 0; p--){
            if(p == b) continue;      
            long long mask = 1LL << p;
            if((x & mask) == 0){         
                long long candidate = baseY + mask;
                if(candidate < x){
                    y = candidate;
                    break;
                }
            }
        }

        if(y == -1){
            cout << -1 << "\n";
        } else {
            cout << y << "\n";
        }
    }
    return 0;
}
