#include <bits/stdc++.h>
using namespace std;

ifstream f("crypto.in");
ofstream g("crypto.out");

const int NMAX = 1e6 + 5;
int a[NMAX], b[NMAX], n, s;

bool check(int val) {
    long long cost = s;
    for (int i = 1; i <= n; i++) {
        if (a[i] < val) {
            if (1LL * (val - a[i]) * b[i] > cost) {
                return false;
            }
            cost -= (val - a[i]) * b[i];
        }
    }
    return true;
}

int main() {
    f >> n >> s;
    for (int i = 1; i <= n; i++) {
        f >> a[i] >> b[i];
    }
    int st = 1;
    int dr = 1e9;
    int sol = 0;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (check(mid)) {
            sol = mid;
            st = mid + 1;
        } else {
            dr = mid - 1;
        }
    }
    g << sol;
    return 0;
}
