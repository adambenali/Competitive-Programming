#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    ll a, b, c, d, cost;
    string s, t;
    char p, q;
    cin >> T;
    while (T--){
        cin >> a >> b >> c >> d;
        cin >> s;
        cin >> t;
        cost = 0;
        for (int i = 0; i < s.size(); i++){
            p = s[i];
            q = t[i];
            if (p == q) continue;
            if (islower(p) && islower(q)) cost += min(a, c + b + d);
            else if (isupper(p) && isupper(q)) cost += min(b, d + a + c);
            else if (islower(p) && isupper(q)){
                if (tolower(p) != tolower(q)) cost += min(c + b, a + c);
                else cost += c;
            }
            else {
                if (tolower(p) != tolower(q)) cost += min(b + d, d + a);
                else cost += d;
            }
        }
        cout << cost << '\n';
    }
}
