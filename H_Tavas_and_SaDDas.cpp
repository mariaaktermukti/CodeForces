#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() 
{
    string n;
    cin >> n;

    int len = n.length();
    int index = 0;
    for (int i = 1; i < len; ++i) 
    {
        index += pow(2, i);
    }

    int binIndex = 0;
    for (int i = 0; i < len; ++i) 
    {
        binIndex <<= 1;
        if (n[i] == '7') 
        {
            binIndex |= 1;
        }
    }
    cout << index + binIndex + 1 << endl;

    return 0;
}
