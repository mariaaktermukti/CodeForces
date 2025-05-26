#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<pair<int64,int64>> pts(n);
        vector<int64> xs(n), ys(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].first >> pts[i].second;
            xs[i] = pts[i].first;
            ys[i] = pts[i].second;
        }
        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int64 x_min1 = xs.front(), x_min2 = xs[1];
        int64 x_max1 = xs.back(),  x_max2 = xs[n-2];
        int64 y_min1 = ys.front(), y_min2 = ys[1];
        int64 y_max1 = ys.back(),  y_max2 = ys[n-2];

        int cnt_xmin1 = int(upper_bound(xs.begin(), xs.end(), x_min1) - lower_bound(xs.begin(), xs.end(), x_min1));
        int cnt_xmax1 = int(upper_bound(xs.begin(), xs.end(), x_max1) - lower_bound(xs.begin(), xs.end(), x_max1));
        int cnt_ymin1 = int(upper_bound(ys.begin(), ys.end(), y_min1) - lower_bound(ys.begin(), ys.end(), y_min1));
        int cnt_ymax1 = int(upper_bound(ys.begin(), ys.end(), y_max1) - lower_bound(ys.begin(), ys.end(), y_max1));

        int64 w_orig = x_max1 - x_min1 + 1;
        int64 h_orig = y_max1 - y_min1 + 1;
        int64 answer = w_orig * h_orig;

        auto ceil_div = [&](int64 a, int64 b){
            return (a + b - 1) / b;
        };
        for(auto &p : pts){
            int64 xi = p.first, yi = p.second;

            int64 xmin_ = x_min1, xmax_ = x_max1;
            if(xi == x_min1 && cnt_xmin1 == 1)    xmin_ = x_min2;
            if(xi == x_max1 && cnt_xmax1 == 1)    xmax_ = x_max2;

            int64 ymin_ = y_min1, ymax_ = y_max1;
            if(yi == y_min1 && cnt_ymin1 == 1)    ymin_ = y_min2;
            if(yi == y_max1 && cnt_ymax1 == 1)    ymax_ = y_max2;

            int64 w0 = xmax_ - xmin_ + 1;
            int64 h0 = ymax_ - ymin_ + 1;
            int64 area0 = w0 * h0;

            int64 cand;
            if(area0 >= n){
                cand = area0;
            } 
            else 
            {
                int64 by_width  = w0 * ceil_div(n, w0);
                int64 by_height = h0 * ceil_div(n, h0);
                cand = min(by_width, by_height);
            }

            answer = min(answer, cand);
        }

        cout << answer << "\n";
    }

    return 0;
}
