#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }

        vector<int> frequency(n+1, 0);
        for (int x : a) 
        {
            if (x <= n) 
                frequency[x]++;
        }

        vector<int> delta(n+2, 0);

        bool flag = true; 
        for (int m = 0; m <= n; m++) 
        {
            if (m > 0 && frequency[m-1] == 0) 
            {
                flag = false;
            }
            if (!flag) break;

            int L = frequency[m];
            int R = n - m;
            if (L <= R) 
            {
                delta[L] += 1;
                delta[R+1] -= 1;
            }
        }

        vector<int> Answer(n+1, 0);
        int running = 0;
        for (int k = 0; k <= n; k++) 
        {
            running = running + delta[k];
            Answer[k] = running;
        }

        for (int k = 0; k <= n; k++) 
        {
            cout << Answer[k] << (k == n ? '\n' : ' ');
        }
    }

    return 0;
}
