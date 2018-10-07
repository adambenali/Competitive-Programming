#include <bits/stdc++.h>

using namespace std;

double f_slow(int m){
    double sm = 0;
    unordered_set<int> D;
    for (int i = 1; i < floor(pow(m, 0.5)) + 1; i++) {
        D.insert(i);
        D.insert((int) m / i);
    }
    for (auto p : D)
        sm += p * (m / p - m / (p + 1));

    return sm;
}

double f_fast(int m){
    double sm = 0;
    for (int p = 1; p < floor(pow(m, 0.5)) + 1; p++)
        sm += m / p;
    sm = 2 * sm - floor(pow(m, 0.5)) * floor(pow(m, 0.5));
    return sm;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        printf("%.6f\n", (f_fast(n - k) + f_fast(k - 1)) / (n - 1));
    }
}
