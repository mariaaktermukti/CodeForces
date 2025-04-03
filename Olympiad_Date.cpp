#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const string TARGET = "01032025";

int findMinSteps(vector<int>& digits) {
    unordered_map<char, int> needed;
    for (char c : TARGET) {
        needed[c]++;
    }

    unordered_map<char, int> current;
    for (int i = 0; i < digits.size(); i++) {
        current[digits[i] + '0']++; 
        bool canForm = true;
        for (char c : TARGET) {
            if (current[c] < needed[c]) {
                canForm = false;
                break;
            }
        }
        if (canForm) {
            return i + 1; 
        }
    }
    return 0; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            cin >> digits[i];
        }
        cout << findMinSteps(digits) << "\n";
    }

    return 0;
}
