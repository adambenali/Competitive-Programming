#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
    // freopen("young.in", "r", stdin);
    int counter, st, min_length, p;
    string s1, s2;
    map <char, int> occ1;
    map <char, int> occ2;
    int t;
    cin >> t;
    while (t--){
        counter = 0;
        st = 0;
        min_length = INT_MAX;
        occ1.clear();
        occ2.clear();
        cin >> s1 >> s2;

        for (p = 0; p < (int) s2.size(); p++) occ2[s2[p]]++;

        for (p = 0; p < (int) s1.size() && counter != (int) s2.size(); p++){
            if (occ2[s1[p]] && occ1[s1[p]] < occ2[s1[p]])
                counter++;
            occ1[s1[p]]++;
        }

        if (counter != (int) s2.size()) {
            cout << -1 << '\n';
            continue;
        }
        while (!occ2[s1[st]] || occ1[s1[st]] > occ2[s1[st]]){
            occ1[s1[st]]--;
            st++;
        }
        min_length = (p - 1) - st + 1;

        for (; p < (int) s1.size(); p++){
            occ1[s1[p]]++;

            while (!occ2[s1[st]] || occ1[s1[st]] > occ2[s1[st]]){
                occ1[s1[st]]--;
                st++;
            }
            min_length = min(min_length, p - st + 1);
        }

        cout << min_length << '\n';
    }
}
