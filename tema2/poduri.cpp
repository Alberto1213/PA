#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sn second

ifstream f("poduri.in");
ofstream g("poduri.out");

const int NMAX = 2050;
const int INF = (1 << 30);

char a[2055][2055];
int n, m, xs, ys, sol = INF;
int d[2055][2055];

bool inside(pair<int, int> p) {
    return p.fs >= 1 && p.fs <= n && p.sn >= 1 && p.sn <= m;
}

pair<int, int> all[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<int, int> vert[] = {{-1, 0}, {1, 0}};

pair<int, int> oriz[] = {{0, -1}, {0, 1}};

int main() {
    f >> n >> m >> xs >> ys;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f >> a[i][j];
        }
    }

    queue<pair<int, int>> que;
    que.push(make_pair(xs, ys));
    d[xs][ys] = 1;

    while (!que.empty()) {
        pair<int, int> nod = que.front();
        que.pop();

        if (a[nod.fs][nod.sn] == 'D') {
            for (int i = 0; i < 4; i++) {
                pair<int, int> new_nod;
                new_nod.fs = nod.fs + all[i].fs;
                new_nod.sn = nod.sn + all[i].sn;
                if (inside(new_nod)) {
                    if (d[new_nod.fs][new_nod.sn] == 0) {
                        if (a[new_nod.fs][new_nod.sn] != '.') {
                            d[new_nod.fs][new_nod.sn] = 1 + d[nod.fs][nod.sn];
                            que.push(new_nod);
                        }
                    }
                } else {
                    sol = min(sol, d[nod.fs][nod.sn] + 1);
                }
            }
        }
        if (a[nod.fs][nod.sn] == 'O') {
            for (int i = 0; i < 2; i++) {
                pair<int, int> new_nod;
                new_nod.fs = nod.fs + oriz[i].fs;
                new_nod.sn = nod.sn + oriz[i].sn;
                if (inside(new_nod)) {
                    if (d[new_nod.fs][new_nod.sn] == 0) {
                        d[new_nod.fs][new_nod.sn] = 1 + d[nod.fs][nod.sn];
                        que.push(new_nod);
                    }
                } else {
                    sol = min(sol, d[nod.fs][nod.sn] + 1);
                }
            }
        }
        if (a[nod.fs][nod.sn] == 'O') {
            for (int i = 0; i < 2; i++) {
                pair<int, int> new_nod;
                new_nod.fs = nod.fs + oriz[i].fs;
                new_nod.sn = nod.sn + oriz[i].sn;
                if (inside(new_nod)) {
                    if (d[new_nod.fs][new_nod.sn] == 0) {
                        d[new_nod.fs][new_nod.sn] = 1 + d[nod.fs][nod.sn];
                        que.push(new_nod);
                    }
                } else {
                    sol = min(sol, d[nod.fs][nod.sn] + 1);
                }
            }
        }
        if (a[nod.fs][nod.sn] == 'V') {
            for (int i = 0; i < 2; i++) {
                pair<int, int> new_nod;
                new_nod.fs = nod.fs + vert[i].fs;
                new_nod.sn = nod.sn + vert[i].sn;
                if (inside(new_nod)) {
                    if (d[new_nod.fs][new_nod.sn] == 0) {
                        d[new_nod.fs][new_nod.sn] = 1 + d[nod.fs][nod.sn];
                        que.push(new_nod);
                    }
                } else {
                    sol = min(sol, d[nod.fs][nod.sn] + 1);
                }
            }
        }
    }
    if (sol == INF) {
        g << -1;
    } else {
        g << sol - 1;
    }
    return 0;
}
