#include <bits/stdc++.h>
using namespace std;

ifstream f("stocks.in");
ofstream g("stocks.out");

const int NMAX = 105;
const int VMAX = 505;
int dp[VMAX][VMAX], a[NMAX], b[NMAX], c[NMAX];
int n, s, loss;

int main() {
    f >> n >> s >> loss;
    for (int i = 1; i <= n; i++) {
        f >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i <= s; i++) {
        for (int j = 0; j <= loss; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= s) {
            for (int j = s; j >= 0; j--) {
                for (int k = 0; k <= loss; k++) {
                    if (dp[j][k] > -1e9) {
                        if (j + a[i] <= s && k + a[i] - b[i] <= loss) {
                            int l = a[i] - b[i];
                            int w = c[i] - a[i];
                            int next = j + a[i];
                            dp[next][k + l] = max(
                                dp[next][k + l], dp[j][k] + w);
                        }
                    }
                }
            }
        }
    }
    int sol = dp[s][loss];
    for (int i = 1; i <= s; i++) {
        for (int j = 0; j <= s; j++) {
            sol = max(sol, dp[i][j]);
        }
    }
    g << sol;
    return 0;
}
