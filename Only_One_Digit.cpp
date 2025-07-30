#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int t;
  cin >> t;
  while(t--) 
  {
    int x;
    cin >> x;
    int mn = 9;
    while(x > 0) 
    {
      mn = min(mn, x % 10);
      x/=10;
    }
    cout << mn << endl;
  }
}