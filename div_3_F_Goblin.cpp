#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    vector<long long> w;
    DSU(int n): p(n), r(n,0), w(n,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        w[a]+=w[b];
        if(r[a]==r[b]) r[a]++;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        // 1) Label zero-segments
        vector<int> seg_id(n, -1);
        vector<int> seg_len;
        for(int i=0, id=0; i<n; ){
            if(s[i]=='0'){
                int j=i;
                while(j<n && s[j]=='0') j++;
                seg_len.push_back(j-i);
                for(int k=i; k<j; k++){
                    seg_id[k]=id;
                }
                id++;
                i=j;
            } else i++;
        }
        int S = seg_len.size();
        int D = 0;
        vector<int> diag_id(n, -1);
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                diag_id[i]=S + (D++);
            }
        }

        // 2) Initialize DSU with S + D nodes
        DSU dsu(S + D);
        // set segment weights
        for(int i=0; i<S; i++){
            dsu.w[i] = 1LL * seg_len[i] * (n - 1);
        }
        // set diagonal weights
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                int id = diag_id[i];
                dsu.w[id] = 1;
            }
        }

        // 3) Union diagonal nodes to adjacent segments
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                int id = diag_id[i];
                if(i>0 && s[i-1]=='0'){
                    dsu.unite(id, seg_id[i-1]);
                }
                if(i+1<n && s[i+1]=='0'){
                    dsu.unite(id, seg_id[i+1]);
                }
            }
        }

        // 4) Find max component weight
        long long ans = 0;
        // Only need to check roots; iterate all nodes
        for(int x=0; x<S+D; x++){
            if(dsu.find(x)==x){
                ans = max(ans, dsu.w[x]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
