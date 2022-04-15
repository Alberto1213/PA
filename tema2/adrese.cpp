#include <bits/stdc++.h>
using namespace std;

ifstream f("adrese.in");
ofstream g("adrese.out");

const int NMAX = 1000;
int n, dad[NMAX];
vector<string> v[NMAX];
map<string, int> hs;
vector<int> b[NMAX];
vector<string> nume;

struct lol {
    string name;
    vector<string> emails;
};

int find(int p) {
    return (p == dad[p] ? p : dad[p] = find(dad[p]));
}

void join(int x, int y) {
    dad[find(x)] = find(y);
}

int main() {
    f >> n;
    iota(dad, dad + n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        f >> s >> k;
        nume.push_back(s);
        for (int j = 0; j < k; j++) {
            string adresa;
            f >> adresa;
            v[i].push_back(adresa);
            if (hs.count(adresa)) {
                join(find(i), find(hs[adresa]));
            } else {
                hs[adresa] = i;
            }
        }
    }
    set<int> sp;
    for (int i = 0; i < n; i++) {
        b[find(i)].push_back(i);
        sp.insert(find(i));
    }
    vector<lol> res;
    for (auto i : sp) {
        vector<string> d;
        map<string, int> s;
        lol p;
        p.name = nume[b[i].back()];
        for (auto j : b[i]) {
            for (auto k : v[j]) {
                s[k]++;
            }
            p.name = min(p.name, nume[j]);
        }
        for (auto it : s) {
            p.emails.push_back(it.first);
        }
        res.push_back(p);
    }
    sort(res.begin(), res.end(), [](const lol &a, const lol &b) {
        if (a.emails.size() != b.emails.size()) {
            return a.emails.size() < b.emails.size();
        } else {
            return a.name < b.name;
        }
    });
    g << res.size() << '\n';
    for (auto i : res) {
        g << i.name << ' ' << i.emails.size() << '\n';
        for (auto j : i.emails) {
            g << j << '\n';
        }
    }
    return 0;
}
