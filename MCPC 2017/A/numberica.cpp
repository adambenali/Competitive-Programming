#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl
#define MAXN 100005

int n;
ll vertices[2 * MAXN];
ll entry[MAXN];
vector<int> graph[MAXN];
vector<int> result;
int deg[MAXN];
bool vis[MAXN];

int in[MAXN];
int out[MAXN];

unordered_map<ll, int> imap;

void conquer(int s) {
    while (graph[s].size()) {
        int nxt = graph[s].back();
        graph[s].pop_back();
        conquer(nxt);
    }
    result.push_back(s);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("numberica.in", "r", stdin);

    int t, d;
    ll t_power;
    cin >> t;
    while (t--) {

        cin >> n >> d;
        imap.clear();
        result.clear();

        t_power = 1;
        for (int i = 0; i < d - 1; i++, t_power *= 10) {}
        for (int i = 0, j = 0; i < n; i++) {
            cin >> entry[i];
            vertices[j++] = entry[i] % t_power;
            vertices[j++] = entry[i] / 10;
        }
        sort(vertices, vertices + 2 * n);

        int u_n = unique(vertices, vertices + 2 * n) - vertices;

        for (int i = 0; i < u_n; i++) {
            imap[vertices[i]] = i;
            out[i] = 0;
            in[i] = 0;

            graph[i].clear();
        }
        for (int i = 0; i < n; i++) {
            ll pre = imap[entry[i] / 10], suff = imap[entry[i] % t_power];
            out[pre]++;
            in[suff]++;
        }
        /* Building the graph */
        for (int i = 0; i < n; i++) {
            ll pre = imap[entry[i] / 10], suff = imap[entry[i] % t_power];
            graph[pre].push_back(suff);
        }

        for (int i = 0; i < u_n; i++) {
            sort(graph[i].rbegin(), graph[i].rend());
        }

        int nok_1 = 0;
        int nok_m1 = 0;
        bool nok_2 = false;
        int start = -1;

        for (int i = 0; i < u_n; i++) {
            if (in[i] - out[i] == 1) nok_1++;
            else if (in[i] - out[i] == -1) {
                start = i;
                nok_m1++;
            } else if (in[i] - out[i] != 0) {
                nok_2 = true;
                break;
            }
        }
        if (nok_2 || nok_1 > 1 || nok_m1 > 1) {
            cout << "Not Connected" << '\n';
            continue;
        }
        if (start == -1)
            start = imap[*min_element(vertices, vertices + u_n)];

        for (int i = 0; i < u_n; i++) deg[i] = 0;
        conquer(start);

        if ((int) result.size() != n + 1) {
            cout << "Not Connected" << '\n';
            continue;
        }

        cout << "Connected" << '\n';

        for (int i = n; i > 1; i--)
            cout << (vertices[result[i]] * 10 + vertices[result[i - 1]] % 10) << ' ';
        cout << (vertices[result[1]] * 10 + vertices[result[0]] % 10);
        cout << '\n';

    }
}
