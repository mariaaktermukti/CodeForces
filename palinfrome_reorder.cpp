#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int odd_count = 0;
    char odd_char = 0;
    for (auto [c, count] : freq) {
        if (count % 2 != 0) {
            odd_count++;
            odd_char = c;
        }
    }

    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string half = "";
    string middle = "";

    for (char c = 'A'; c <= 'Z'; c++) {
        if (freq.count(c)) {
            int half_count = freq[c] / 2;
            half += string(half_count, c);
            if (freq[c] % 2 != 0) {
                middle = string(1, c);
            }
        }
    }

    string reversed_half = half;
    reverse(reversed_half.begin(), reversed_half.end());
    cout << half + middle + reversed_half << "\n";

    return 0;
}
