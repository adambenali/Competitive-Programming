#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl
const int INF = 0x3f3f3f3f;

#define MAXN 1005
#define MAXK 510

int dp[MAXN][MAXK][4][9];
int a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, ans, s, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        string S;
        cin >> S;
        for (int i = 0; i < n; i++) {
            switch(S[i]) {
                case 'E':
                    a[i] = 1; break;
                case 'S':
                    a[i] = 2; break;
                case 'W':
                    a[i] = 3; break;
                case 'N':
                    a[i] = 0; break;
            }
        }

        for (int i = 0; i <= n; i++)
            for (int d = 0; d <= 2 * (n / 4); d++)
                for (int p = 0; p < 4; p++)
                    for (int c = 0; c < 7; c++)
                        dp[i][d][p][c] = INF;

        dp[0][n / 4 + 0][0][3 + 0] = 0;

        for (int i = 0; i < n; i++) {
            for (int d1 = n / 4 + 0, d2 = n / 4 - 0; d1 <= n / 4 + 2 * ((i + 1) / 4); d1++, d2--) {
                for (int p = 0; p < 4; p++) {
                    for (int c1 = 0, c2 = 0; c1 < 4 && c1 < i + 1 - 4 * (d1 - n / 4); c1++, c2--) {
                        for (auto d : {d1, d2}) {
                            for (auto c : {c1, c2}) {
                                s = (p != a[i] && (p + 2) % 4 != a[i]);
                                dp[i + 1][d][p][3 + c] = min(dp[i + 1][d][p][3 + c], s + dp[i][d][p][3 + c]);

                                s = ((p + 1) % 4 != a[i]);
                                dp[i + 1][d + ((c + 1) == 4)][(p + 1) % 4][3 + (c + 1) % 4] = min(dp[i + 1][d + ((c + 1) == 4)][(p + 1) % 4][3 + (c + 1) % 4], s + dp[i][d][p][3 + c]);

                                s = ((p + 3) % 4 != a[i]);
                                dp[i + 1][d - ((c - 1) == -4)][(p + 3) % 4][3 + (c - 1) % 4] = min(dp[i + 1][d - ((c - 1) == -4)][(p + 3) % 4][3 + (c - 1) % 4], s + dp[i][d][p][3 + c]);
                            }
                        }
                    }
                }
            }
        }

        if (n < 4 * k) {
            cout << -1 << '\n';
            continue;
        }
        ans = INF;
        for (int p = 0; p < 4; p++) {
            for (int c = 0; c < 7; c++) {
                ans = min(ans, dp[n][n / 4 + k][p][c]);
            }
        }
        cout << ans << '\n';
    }
}
