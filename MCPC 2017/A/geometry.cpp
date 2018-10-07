#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int t, d, a, b;
    cin >> t;
    while (t--){
        cin >> d >> a >> b;
        cout << a * a * d << " " << b * b * d << " " << (a *a + b * b) * d << endl;
    }
}