#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, d;
	cin >> T;
	for(int p = 1; p <= T; p++)
	{
		cin >> n;
		cin >> d;
		vector < vector <int> > pts;
		int deg[n];
		fill(deg, deg + n, 0);
	    for(int u = 1;u <= n; u++){
	        vector <int> tmp;
	        int inp;
	        cin >> inp;
	        tmp.push_back(inp);
	        cin >> inp;
	        tmp.push_back(inp);
	        pts.push_back(tmp);
	    }
	    for (int i = 0; i < n; i++){
            for (int j = i + 1;j < n; j++){
                if (abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]) <= d){
                    deg[i] += 1;
                    deg[j] += 1;
                }
            }
	    }
	    cout << distance(deg, max_element(deg, deg + n)) + 1 << endl;
	}
}
