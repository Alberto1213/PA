#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int maxN = 10001;

int n, m;
int cntEuler;

vector<int> v[10001];
bool vis[10001], is_art[10001];

int subarb[10001];
int lvl[10001], low[10001], tin[10001];


void dfs(int nod, int tata) {
    subarb[nod] = 1;
    vis[nod] = true;
    cntEuler ++;
    tin[nod] = low[nod] = cntEuler;

    vector<int> sons;

    for (auto it : v[nod]) {
        if (it == tata) {
            continue;
        }

        if (vis[it] == false) {
            lvl[it] = lvl[nod] + 1;
            dfs(it, nod);
            sons.push_back(it);

            low[nod] = min(low[nod], low[it]);
            if (low[it] >= tin[nod] && nod != 1) {
                is_art[nod] = true;
            }
        } else {
            if (tin[it] < low[nod]) {
                low[nod] = tin[it];
            }
        }
    }

    for (auto it : sons) {
        subarb[nod] += subarb[it];
    }
}

int main() {
    ifstream f("retea.in");
    ofstream g("retea.out");

    f >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        f >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    lvl[1] = 1;
    dfs(1, 0);

    if (v[1].size() > 1) {
        is_art[1] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (is_art[i] == false) {
            g << 2 * (n-1) << '\n';
        } else {
            int result = n * (n-1);
            int nr = n-1;

            for (auto it : v[i]) {
                if (lvl[it] == lvl[i] + 1 && low[it] >= tin[i]) {
                    nr -= subarb[it];
                    result -= subarb[it] * (subarb[it]-1);
                }
            }

            result -= nr * (nr-1);
            g << result << '\n';
        }
    }

    return 0;
}
