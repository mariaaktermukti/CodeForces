#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int n;
        long long m;
        cin >> n >> m;

        long long px = 0;
        int py = 0;
        long long points = 0;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            int y;
            cin >> x >> y;

            points += (x - px);
            if (((x - px + 2) % 2) != ((y - py + 2) % 2))
                points--;

            px = x;
            py = y;
        }

        if (px != m)
            points += (m - px);

        cout << points << '\n';
    }
    return 0;
}
