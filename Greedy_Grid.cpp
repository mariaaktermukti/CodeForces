#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;

        if (n == 1 || m == 1 || (n == 2 && m == 2)) 
        {
            cout << "NO\n";
        } 
        else 
        {
            cout << "YES\n";
        }
    }
    return 0;
}
