#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canForm(long long x, int k, const vector<long long>& a) {
    long long total = 0;
    for (long long students : a) {
        total += min(students, x); 
    }
    return total >= x * k;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<long long> a(n);
    long long totalStudents = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totalStudents += a[i];
    }

    long long left = 0, right = totalStudents / k, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canForm(mid, k, a)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
