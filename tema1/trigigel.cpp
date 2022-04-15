#include <bits/stdc++.h>
using namespace std;

ifstream f("trigigel.in");
ofstream g("trigigel.out");

const long long MOD = 1e9 + 7;
long long a[5][5], b[5][5], sol[5][5], n;

void inmultire(long long m1[5][5], long long m2[5][5]) {
    long long m3[5][5];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            m3[i][j] = 0;
            for (int k = 1; k <= 4; k++) {
                m3[i][j] = (m3[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            m1[i][j] = m3[i][j];
        }
    }
}

void exponentiere() {
    while (n > 0) {
        if (n % 2) {
            inmultire(sol, b);
        }
        inmultire(b, b);
        n /= 2;
    }
}

int main() {
    f >> n;
    if (n == 1) {
        g << 1;
        return 0;
    }
    if (n == 2) {
        g << 3;
        return 0;
    }
    for (int i = 1; i <= 4; i++) {
        sol[i][i] = 1;
    }
    a[1][1] = 1;
    a[1][2] = 1;
    a[1][3] = 2;
    a[1][4] = 3;
    b[1][1] = 1;
    b[1][4] = 1;
    b[2][4] = 1;
    b[3][2] = 1;
    b[4][3] = 1;
    b[4][4] = 1;
    n -= 3;
    exponentiere();
    inmultire(a, sol);
    g << ((a[1][2] + a[1][3]) % MOD + a[1][4]) % MOD;
    return 0;
}
