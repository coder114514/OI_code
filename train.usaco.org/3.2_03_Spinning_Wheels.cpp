/*
ID: 18817371
LANG: C++11
PROB: spin
*/

#include <bits/stdc++.h>
using namespace std;

int rSpeed[6];
vector<int> wStart[6];
vector<int> wExt[6];

int cover[360];

int main() {
    // freopen("spin.in", "r", stdin);
    // freopen("spin.out", "w", stdout);
    for (int i = 1; i <= 5; i++) {
        cin >> rSpeed[i];
        int nPair;
        cin >> nPair;
        for (int p = 1; p <= nPair; p++) {
            int s, e;
            cin >> s >> e;
            wStart[i].push_back(s);
            wExt[i].push_back(e);
        }
    }
    for (int t = 0; t < 360; t++) {
        memset(cover, 0, sizeof(cover));
        for (int i = 1; i <= 5; i++) {
            for (int ia = 0; ia < wStart[i].size(); ia++) {
                int s = wStart[i][ia];
                int e = wExt[i][ia];
                s += t * rSpeed[i] % 360;
                s %= 360;
                for (int a = s; a <= s + e; a++) {
                    cover[a%360]++;
                }
            }
        }
        for (int a = 0; a < 360; a++) {
            if (cover[a] == 5) {
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << "none" << endl;
    return 0;
}
