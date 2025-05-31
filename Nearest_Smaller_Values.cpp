#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> x[i];
    }

    vector<int> ans(n, 0);
    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; i++) 
    {
        while (!st.empty() && x[st.back()] >= x[i]) 
        {
            st.pop_back();
        }

        if (st.empty()) 
        {
            ans[i] = 0;
        } 
        else 
        {
            ans[i] = st.back() + 1;
        }
        st.push_back(i);
    }

    for (int i = 0; i < n; i++) 
    {
        cout << ans[i] << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
