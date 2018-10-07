#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl

#define MAXN 25500
#define EPS 1e-8

int x[MAXN];
int y[MAXN];

double ang(double u, double v) {
    double res;
    if (v >= 0) {
        if (u <= 0) {
            res = M_PI - asin(v / sqrt(v * v + u * u));
        } else {
            res = asin(v / sqrt(v * v + u * u));
        }
    } else {
        if (u <= 0) {
            res = M_PI + asin(abs(v) / sqrt(v * v + u * u));
        } else {
            res = 2 * M_PI - asin(abs(v) / sqrt(v * v + u * u));
        }
    }

    return res;
}

bool blocked(int n, double r, double t) {
    vector<pair<double, double>> angles;

    for (int i = 0; i < n; i++) {
        if (((x[i] <= 0) && (y[i] >= 0) && (x[i] + r * t / 2 >= 0) && (y[i] - r * t / 2 <= 0)) ||
            ((x[i] <= 0) && (y[i] <= 0) && (x[i] + r * t / 2) >= 0 && (y[i] + r * t / 2) >= 0) ||
            ((x[i] >= 0) && (y[i] >= 0) && (x[i] - r * t / 2 <= 0) && (y[i] - r * t / 2 <= 0)) ||
            ((x[i] >= 0) && (y[i] <= 0) && (x[i] - r * t / 2) <= 0 && (y[i] + r * t / 2) >= 0)) {
                return true;
            }
    }

    for (int i = 0; i < n; i++) {
        double s = 1e9, l = -1;
        if (x[i] >= 0 && (y[i] - r * t / 2) * (y[i] + r * t / 2) <= 0) {
            l = ang(x[i] - r * t / 2, y[i] + r * t / 2) + 2 * M_PI;
            s = ang(x[i] - r * t / 2, y[i] - r * t / 2);
        } else {
            for (auto sn1 : {-1, 1}) {
                for (auto sn2 : {-1, 1}) {
                    s = min(s, ang(x[i] + sn1 * r * t / 2, y[i] + sn2 * r * t / 2));
                    l = max(l, ang(x[i] + sn1 * r * t / 2, y[i] + sn2 * r * t / 2));
                }
            }
        }

        angles.push_back(make_pair(s, l));
    }

    sort(angles.begin(), angles.end());

    double max_angle = -1;
    for (int i = 0; i < n - 1; i++) {
        max_angle = max(angles[i].second, max_angle);
        if (angles[i + 1].first > max_angle) return false;
    }

    if (angles[0].first + 2 * M_PI > max(max_angle, angles[n - 1].second)) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(3);

    // freopen("squares.in", "r", stdin);

    int t, n;
    double r;
    cin >> t;
    while (t--) {
        cin >> n >> r;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        double s = 0, e = 1e7, m;
        while (e - s > 1e-4) {
            m = (s + e) / 2;
            if (blocked(n, r, m)) e = m;
            else s = m;
        }
        cout << fixed;
        cout << m << '\n';
    }
}
