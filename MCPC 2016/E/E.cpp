#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

unsigned long long h1[500001], h2[500001], pw[500001];
long long H1[500001], H2[500001], Pw[500001];


/*bool isAs(string s, int k){
    if (k % 2 == 1) return 0;
    for(int i = 0; i < k / 2; i++){
        if (s[i] - '0' == s[k - i - 1] - '0')
            return false;
    }
    return true;
}*/

int main(){
    int T, n, r, i;
    int a, b;
    long long int ans;
    char s[500001];
    
    cin >> T;
    while (T--){
        cin >> n;
        scanf("%s", s + 1);
        for (i = 1; i <= n; i++){
            h1[i] = h1[i - 1] * 2 + s[i] - '0';
            H1[i] = (H1[i - 1] * 2 + s[i] - '0' ) % M;
        }
        for(i = n; i >= 1; i--){
            h2[i] = h2[i + 1] * 2 + '1' - s[i];
            H2[i] = (H2[i + 1] * 2 + '1' - s[i]) % M;
        }
        pw[0] = Pw[0] = 1;
        for (i = 1; i <= n; i++){
            pw[i] = pw[i - 1] * 2;
            Pw[i] = Pw[i-1] * 2 % M;
        }
        ans = 0;
        for (int m = 0; m < n - 1; m++){
            int i = m + 1;
            r = min(i, n - i);
            a = 1;
            b = r;
            int res = 0;
            while (b - a >= 0){
                r = (a + b) / 2;
                if (h1[i] - h1[i - r] * pw[r] == h2[i + 1] - h2[i + 1 + r] * pw[r] && (H1[i] - H1[i - r] * Pw[r] % M + M) % M == (H2[i + 1] - H2[i + 1 + r] * Pw[r] % M + M) % M){
                    a = r + 1;
                    res = r;
             }
                else
                    b = r - 1;
            }
            ans += res;
        }
        cout << ans << endl;
    }
    return 0;
}
