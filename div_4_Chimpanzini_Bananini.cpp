#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int q;
        cin >> q;

        deque<int> dq;  
        ll S = 0;       
        ll R = 0;        
        int n = 0;       
        bool rev = false;

        while(q--){
            int s;
            cin >> s;

            if(s == 1){
                if(n > 0){
                    if(!rev){
                        int x = dq.back();
                        R += S - 1LL*x*n;
                        dq.pop_back();
                        dq.push_front(x);
                    } else {
                        int x = dq.front();
                        R += -S + 1LL*x*n;
                        dq.pop_front();
                        dq.push_back(x);
                    }
                }
            }
            else if(s == 2){
                R = 1LL*(n+1)*S - R;
                rev = !rev;
            }
            else {
                int k;
                cin >> k;
                if(!rev){
                    R += 1LL*k*(n+1);
                    dq.push_back(k);
                } else {
                    R += S + k;
                    dq.push_front(k);
                }
                S += k;
                n++;
            }

            cout << R << "\n";
        }
    }
    return 0;
}
