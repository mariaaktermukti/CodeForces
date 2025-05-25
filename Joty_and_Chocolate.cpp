#include <iostream>
#include <algorithm> 
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    ll countA = n / a;
    ll countB = n / b;
    ll countBoth = n / lcm(a, b);
    ll result = countA * p + countB * q - countBoth * min(p, q);

    cout << result << endl;
    return 0;
}
