#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int &x : a) std::cin >> x;

        int robin_gold = 0;
        int people_helped = 0;

        for (int x : a) {
            if (x >= k) {
                robin_gold += x;
            } else if (x == 0 && robin_gold > 0) {
                robin_gold--;
                people_helped++;
            }
        }

        std::cout << people_helped << '\n';
    }
    return 0;
}
