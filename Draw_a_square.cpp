#include <iostream>
#include <cmath>
using namespace std;

int dist_sq(int x1, int y1, int x2, int y2) 
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main()
{
    int t;
    cin >> t;  
    
    while (t--) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        
        int Lx = -l, Ly = 0;
        int Rx = r, Ry = 0;
        int Dx = 0, Dy = -d;
        int Ux = 0, Uy = u;
        
        int distLD = dist_sq(Lx, Ly, Dx, Dy);
        int distLU = dist_sq(Lx, Ly, Ux, Uy);
        int distRD = dist_sq(Rx, Ry, Dx, Dy);
        int distRU = dist_sq(Rx, Ry, Ux, Uy);
        int distLD_RU = dist_sq(Lx, Ly, Rx, Ry);  
        int distDU = dist_sq(Dx, Dy, Ux, Uy);  
        
        if (distLD == distLU && distLD == distRD && distLD == distRU && distLD_RU == distDU) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
