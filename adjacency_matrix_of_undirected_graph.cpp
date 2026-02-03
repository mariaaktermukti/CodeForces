#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    int adj_matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj_matrix[i][j]=0;
        }
    }
    // shortcut
    // memset(adj_matrix,0,sizeof(adj_matrix));



    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >> a >>b;
        adj_matrix[a][b]=1;
        adj_matrix[b][a]=1;
    }

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
          {
             cout << adj_matrix[i][j] << " ";
          }
        cout << endl;
    }
  
    return 0;
}