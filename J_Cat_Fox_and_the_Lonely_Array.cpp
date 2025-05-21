#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool check(vector<int>& v, int mid,int ori)
{
    vector<int>frekbit(31);
    for (int i = 0; i < mid; i++)
    {
        int x = v[i];
 
        for (int j = 30; j >= 0; j--)
        {
            if (x>=(1<<j))
            {
                x -= (1<<j);
                frekbit[j]++;
            }
        }
    }
    int or2 = 0;
    for (int i = 0; i < frekbit.size(); i++)
    {
        if (frekbit[i] > 0)
        {
            or2 += (1 << i);
        }
    }
    if (or2 != ori)
    {
        return false;
    }
    for (int i = 1; i + mid - 1 < v.size(); i++)
    {
        int x = v[i - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]--;
                if (frekbit[j] == 0)
                {
                    or2 -= (1 << j);
                }
            }
        }
        x = v[i+mid - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]++;
                if (frekbit[j] == 1)
                {
                    or2 += (1 << j);
                }
            }
        }
        if (or2 != ori)
        {
            return false;
        }
    }
    return true;
 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        int ori = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            ori |= v[i];
        }
        int lo = 1;
        int hi = n;
        while (lo < hi)
        {
            int mid = (lo+hi) / 2;
            if (check(v,mid,ori) == true)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}