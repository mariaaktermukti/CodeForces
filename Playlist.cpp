#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    unordered_map<int, int, custom_hash> freq;
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; ++right) {
        freq[songs[right]]++;

        while (freq[songs[right]] > 1) {
            freq[songs[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << '\n';
    return 0;
}
