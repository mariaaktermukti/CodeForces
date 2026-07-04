#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        string x = "", y = "";
        int openX = 0, openY = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                x += a[i];
                y += b[i];
                if (a[i] == '(')
                {
                    openX++;
                    openY++;
                }
            }
            else
            {
                if (openX <= openY)
                {
                    x += '(';
                    y += ')';
                    openX++;
                }
                else
                {
                    x += ')';
                    y += '(';
                    openY++;
                }
            }
        }

        int balX = 0, balY = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            balX += (x[i] == '(' ? 1 : -1);
            balY += (y[i] == '(' ? 1 : -1);

            if (balX < 0 || balY < 0)
            {
                ok = false;
                break;
            }
        }

        if (balX != 0 || balY != 0)
            ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}