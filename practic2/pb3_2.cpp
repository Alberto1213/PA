#include <bits/stdc++.h>

using namespace std;
#define N 200200

int p[N], d[N], used[N], marked[N];
vector<int> a[N];

void dfs(int k, int depth) {
    used[k] = 1;
    d[k] = depth;
    for (int it = 0; it < a[k].size(); ++it) {
        if (!used[a[k][it]]) {
            used[a[k][it]] = 1;
            p[a[k][it]] = k;
            dfs(a[k][it], depth + 1);
        }
    }
}

void mark(int k) {
    marked[k] = 1;
    if (p[k]) {
        mark(p[k]);
    }
}

int query() {
    int n, start = 1, mx = 0;
    cin >> n;
    vector<int> s(n);
    for (int it = 0; it < n; ++it) {
        cin >> s[it];
        if (mx < d[s[it]]) {
            mx = d[s[it]];
            start = s[it];
        }
    }
    memset(marked, 0, sizeof(marked));
    mark(start);
    for (int it = 0; it < n; ++it) {
        if (!marked[s[it]]) {
            if (!p[s[it]]) {
                return 0;
            } else if (!marked[p[s[it]]]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n, m, x, y, i;
    cin >> n >> m;
    for (i = 1; i < n; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    p[1] = 0;
    dfs(1, 0);
    string answer[2] = {"NO\n", "YES\n"};
    for (i = 0; i < m; ++i) {
        cout << answer[query()];
    }
    return 0;
}