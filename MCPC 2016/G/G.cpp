#include <bits/stdc++.h>

using namespace std;

int circles(double houses[],int n,double r,int d){
    double currentCircle[] = {houses[0], houses[0] + 2 * r};
    int c = 1;
    int i = 0;
    while (i < n && c != d + 1){
        if (houses[i] > currentCircle[1] || houses[i] < currentCircle[0]){
            currentCircle[0] = houses[i];
            currentCircle[1] = houses[i] + 2 * r;
            c += 1;
        }
        i++;
    }
    return c;
}
int main()
{
    int T, n, d;
    double x1, x2, y, r;
	cin >> T;
	for (int p = 1; p <= T; p++)
	{
		cin>>n;
		cin>>d;
		double houses[n];
	    for (int u = 0; u < n; u++){
	        cin >> houses[u];
	    }
	    sort(houses, houses + n);
      r = (houses[n - 1] - houses[0]) / 2;
      x2 = r;
      x1 = 0;
      y = 0;
      while (abs(x2 - x1) > 0.0001){
          if (circles(houses, n, r, d) <= d){
              y = r;
              r = (x1 + y) / 2;
              }
          else{
              r = (x2 + y) / 2;
              x1 = x2;}
          x2 = r;
      }
      printf("%.3f\n", r);
    }
    return 0;
}
