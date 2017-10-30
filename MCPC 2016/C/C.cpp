#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, x;
    cin >> T;
    for (int p = 1; p <= T; p++)
    {
        cin >> n;
        vector<vector <int>> A;
        for(int u = 0; u < n; u++){
            vector <int> tmp;
            for(int v=0;v<n;v++){
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            A.push_back(tmp);
        }
        x = 0;
        for (int u = 0; u < n; u++){
            for (int v = u;v < n; v++){
                if ((A[0][u] ^ A[0][v]) != A[u][v]){
                    cout << -1 << endl;
                    x = 1;
                    break;
                }
            }
            if (x == 1)
                break;
            }
    if (x == 0){
        for (int i = 0; i < n; i++){
            cout << A[0][i];
            if (i != n - 1) cout << " ";
        }
        printf("\n");
        }
    }
    return 0;
}
