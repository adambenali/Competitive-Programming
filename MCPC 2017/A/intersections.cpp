#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long int n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        cout << k * (n - k) + (n - k) * (n - k - 1) / 2 << endl;
    }
}