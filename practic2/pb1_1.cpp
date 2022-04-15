//problema 1_1

#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5;
vector<pair<int, int>> graf[NMAX + 1];
bool use[NMAX + 1];
int a[NMAX + 1];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	while(m--) {
		int x, y, c;
		cin >> x >> y >> c;
		graf[x].push_back({y, c});
		graf[y].push_back({x, c});
	}
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
		use[a[i]] = 1;
	}
	int sol = 1e9;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < (int)graf[a[i]].size(); j++) {
			int next = graf[a[i]][j].first;
			int cost = graf[a[i]][j].second;
			if(!use[next]) {
				sol = min(sol, cost);
			}
		}
	} 
	if(sol == 1e9) {
		cout << -1;
	} else {
		cout << sol;
	}
	return 0;
}