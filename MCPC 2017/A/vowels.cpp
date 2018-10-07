#include <bits/stdc++.h>

using namespace std;

set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    long long int n, answer;
    string s;
    int vowels;
    map<string, int> words;
    int before[27];
    cin >> t;
    while (t--){
        words.clear();
        cin >> n;
        answer = 0;
        for (int i = 0; i < 27; i++) before[i] = 0;
        for (int i = 0; i < n; i++){
            cin >> s;
            vowels = 0;
            for (size_t j = 0; j < s.size(); j++){
                if (VOWELS.count(s[j])) vowels++;
            }

            if (!words.count(s)) {
                words[s] = before[vowels];
                before[vowels]++;
            }
            else words[s] = before[vowels];
        }
        for (auto p : words) {
            answer += p.second;
        }
        cout << answer << '\n';
    }
}
