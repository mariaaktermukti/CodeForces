#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        vector<int> a(n);
        cin >> a[0];

        int or_value = a[0];
        int and_value = a[0];

        for (int i = 1; i < n; ++i) 
        {
            cin >> a[i];
            or_value |= a[i];  
            and_value &= a[i];   
        }

        cout << or_value - and_value << endl;
    }

    return 0;
}
