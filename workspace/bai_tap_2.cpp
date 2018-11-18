#include <iostream>
using namespace std;
int main()
{
    int m,n,Q;
    cin >> m>> n>> Q; 
    int a[m][n];
    for (int i=0;i<m;++i)
    {   for (int j=0;j<n;++j)
        {
            cin >> a[i][j];// cho de sai
        }
    }    
    int b[Q][2];     
    for (int l=0;l<Q;++l){
        for (int k=0;k<2;++k){
            cin >> b[l][k];
            
        }
        cout << a[b[l][0] - 1][b[l][1] - 1] << endl;
    }
    // cout <<a[b[Q][2]];
    return 0;
    
}