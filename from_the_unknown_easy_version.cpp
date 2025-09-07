#include <bits/stdc++.h>
using namespace std;

void get_answer(int L, int R)
{
    int len = R - L + 1;
    cout << "? " << len * 2 << " ";
    for (int i = 1; i <= len; i++)
    {
        cout << L << " " << i << " ";
    }
    cout << endl;
    cout.flush();

    int response;
    cin >> response;
    if (response == -1)
        exit(0);

    int W = len * 2 - response + L;
    cout << "! " << W << endl;
    cout.flush();
}

void solve_test()
{
    int n = 100000;

    cout << "? " << n << " ";
    for (int i = 0; i < n; i++)
        cout << "1 ";
    cout << endl;
    cout.flush();

    int r1;
    cin >> r1;
    if (r1 == -1)
        exit(0);

    if (r1 == 1)
    {
        cout << "! " << n << endl;
        cout.flush();
        return;
    }

    int L = -1, R = -1;
    for (int i = 1; i <= n; i++)
    {
        if ((n + i - 1) / i == r1)
        {
            if (L == -1)
                L = i;
            R = i;
        }
    }

    get_answer(L, R);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve_test();
    }
}
