//problema 2_1

#include <bits/stdc++.h>
using namespace std;

const int NMAX = 3 * 1e3;
int a[NMAX + 1][NMAX + 1], b[NMAX + 1][NMAX + 1];
int n, m, freq[NMAX * NMAX + 1], cnt;

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    b[x][y] = cnt;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inside(nx, ny) && b[nx][ny] == 0 && a[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] == 0 && a[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] > 0) {
                bool flag = false;
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(inside(ni, nj) && a[ni][nj] == -1) {
                        flag = true;
                    }
                }
                if(flag) {
                    freq[b[i][j]]++;
                }
            }
        }
    }
    vector<int> res;
    for(int i = 1; i <= n * m; i++) {
        if(freq[i] > 0) {
            res.push_back(freq[i]);
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}