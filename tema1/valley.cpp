#include <bits/stdc++.h>
using namespace std;

ifstream f("valley.in");
ofstream g("valley.out");

const int NMAX = 1e6 + 5;
long long a[NMAX], st[NMAX], dr[NMAX], b[NMAX], c[NMAX];

int main() {
    int n;
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }
    st[1] = 0;
    for (int i = 2; i <= n; i++) {
        st[i] = st[i - 1];
        if (b[i] > b[i - 1]) {
            st[i] += b[i] - b[i - 1];
            b[i] = b[i - 1];
        }
    }
    dr[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        dr[i] = dr[i + 1];
        if (c[i] > c[i + 1]) {
            dr[i] += c[i] - c[i + 1];
            c[i] = c[i + 1];
        }
    }
    long long sol = 1e18;
    for (int i = 2; i <= n - 1; i++) {
        long long s = 0;
        long long x = a[i];
        if (x > b[i - 1]) {
            s += x - b[i - 1];
            x = b[i - 1];
        }
        if (x > c[i + 1]) {
            s += x - c[i + 1];
            x = c[i + 1];
        }
        sol = min(sol, st[i - 1] + s + dr[i + 1]);
    }
    g << sol;
    return 0;
}
