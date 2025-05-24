#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<pair<int,int>> movies(n);

    for(int i = 0; i < n; i++) 
    {
        cin >> movies[i].first >> movies[i].second;  
    }

    sort(movies.begin(), movies.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
        return x.second < y.second;
    });

    int count = 0;
    int last_end = 0;

    for (auto &movie : movies) 
    {
        if (movie.first >= last_end) 
        {
            count++;
            last_end = movie.second;
        }
    }

    cout << count << "\n";
    return 0;
}
