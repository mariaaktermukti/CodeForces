#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	      int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
        cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]) ;
                break;
            }
        }
        int c=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
            c=c+1;      
            }
        }
        if(c==0)
        cout<<"yes"<<endl;
        else
        cout<<"no"<<endl;
        
    }
	return 0;
}