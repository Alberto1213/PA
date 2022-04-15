#include <bits/stdc++.h>
using namespace std;

ifstream f("ridge.in");
ofstream g("ridge.out");

const int NMAX = 1e6 + 5;
long long h[NMAX], c[NMAX], d[NMAX][3];
int n;

long long min3(long long a, long long b, long long c) {
    return min(a, min(b, c));
}

int main() {
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> h[i] >> c[i];
    }
    d[1][0] = 0;
    d[1][1] = c[1];
    d[1][2] = 2 * c[1];
    for (int i = 2; i <= n; i++) {
        if (h[i] > h[i - 1] + 2) {
            d[i][0] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
            d[i][1] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + c[i];
            d[i][2] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] < h[i - 1] - 2) {
            d[i][0] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
            d[i][1] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + c[i];
            d[i][2] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] == h[i - 1] - 2) {
            d[i][0] = min(d[i - 1][0], d[i - 1][1]);
            d[i][1] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + c[i];
            d[i][2] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] == h[i - 1] - 1) {
            d[i][0] = min(d[i - 1][0], d[i - 1][2]);
            d[i][1] = min(d[i - 1][0], d[i - 1][1]) + c[i];
            d[i][2] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] == h[i - 1]) {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]);
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + c[i];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + 2 * c[i];
        }
        if (h[i] == h[i - 1] + 1) {
            d[i][0] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
            d[i][1] = min(d[i - 1][1], d[i - 1][2]) + c[i];
            d[i][2] = min(d[i - 1][0], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] == h[i - 1] + 2) {
            d[i][0] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]);
            d[i][1] = min3(d[i - 1][0], d[i - 1][1], d[i - 1][2]) + c[i];
            d[i][2] = min(d[i - 1][1], d[i - 1][2]) + 2 * c[i];
        }
        if (h[i] == 1) {
            d[i][2] = 1e18;
        }
        if (h[i] == 0) {
            d[i][1] = d[i][2] = 1e18;
        }
    }
    g << min3(d[n][0], d[n][1], d[n][2]);
    return 0;
}
