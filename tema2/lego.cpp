#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int kmaxStack = 11;
const int maxN = 1001;
const int INF = (1<<30);

int n, k, t;
int optimal;

int sol[11];
int stk[11];

int dp[1001];

ifstream f("lego.in");
ofstream g("lego.out");

void printSol(int val) {
    g << val << '\n';
    for (int i = 1; i <= n; i++) {
        g << sol[i] << ' ';
    }
}

int checkSol(int k) {
    int limit = stk[n] * t;
    for (int i = 1; i <= limit; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;
    while (true) {
        bool flag = false;
        for (int i = limit; i >= 0; i--) {
            if ( dp[i] < t ) {
                for (int j = 1; j <= n; j++) {
                    if ( i + stk[j] > limit ) {
                        break;
                    }
                    if (dp[i] + 1 < dp[i + stk[j]]) {
                        dp[i + stk[j]] = dp[i] + 1;
                        flag = true;
                    }
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    int res = 0;
    int cnt = 0;
    for (int i = 1; i <= limit; i++) {
        if (dp[i] > t) {
            cnt = 0;
        } else {
            cnt++;
        }
        res = max(res, cnt);
    }
    return res;
}


void updateSol(int val) {
    optimal = val;
    for (int i = 1; i <= n; i++) {
        sol[i] = stk[i];
    }
}

void bkt(int step) {
    if (step == n + 1) {
        int value = checkSol(step);
        if (value > optimal) {
            updateSol(value);

            if (value == k * t) {
                printSol(value);
                exit(0);
            }
        }
    } else {
    	int FirstVal = stk[step - 1] + 1;
        for (int i = FirstVal; i <= k; i++) {
            stk[step] = i;
            bkt(step+1);
        }
    }
}

int main() {
    f >> k >> n >> t;

    stk[1] = 1;
    bkt(2);

    printSol(optimal);

    return 0;
}
