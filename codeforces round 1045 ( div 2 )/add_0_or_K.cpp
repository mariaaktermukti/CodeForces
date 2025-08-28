#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &i : a)
        {
            cin >> i;
            i += (i % (k + 1)) * k;
        }
        for (auto i : a)
            cout << i << ' ';
        cout << '\n';
    }
}