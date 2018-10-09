#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("self.in", "r", stdin);
    int t;
    string s;
    cin >> t;
    int cnt[10];
    bool self;
    while (t--){
        self = true;
        memset(cnt, 0, 10 * sizeof(int));
        cin >> s;
        for (size_t i = 0; i < s.size(); i++) cnt[s[i] - '0']++;
        for (size_t i = 0; i < s.size(); i++) {
            if (cnt[i] != s[i] - '0') {
                self = false;
                break;
            }
        }
        cout << ((self) ? "self-describing" : "not self-describing") << endl;
    }
}
