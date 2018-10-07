#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define MAXN 100000

int v[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) cin >> v[i];

        priority_queue<int,vector<int>,greater<int>> q;
        for (int i = 0; i < m; i++) q.push(v[i]);
        for (int i = 0; i < k - 1; i++) {
            q.pop();
            if (i + m < n) q.push(v[i + m]);
        }
        cout << q.top() << '\n';
    }
}
