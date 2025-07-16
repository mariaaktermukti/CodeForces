#include <iostream>
#include <vector>
#include <map>
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
        map<int, int> freq; 

        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        int score = 0;
        for (auto &entry : freq) 
        {
            score = score + entry.second / 2;
        }

        cout << score << endl;
    }

    return 0;
}
