/*
ID: 18817371
LANG: C++11
PROB: fence
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev;
    bool vis;
};

bool operator<(const Edge& e1, const Edge& e2) {
    return e1.to < e2.to;
}

int nF;
vector<Edge> e[1034];
int deg[1034];
int revtop[1034];

int ans[1034];
int iCyc;

void Hierholzer(int x) {
    for (Edge& w : e[x]) {
        if (!w.vis) {
            w.vis = true;
            e[w.to][w.rev].vis = true;
            Hierholzer(w.to);
        }
    }
    ans[++iCyc] = x;
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    scanf("%d", &nF);
    for (int i = 1; i <= nF; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(Edge{v, -1, false});
        e[v].push_back(Edge{u, -1, false});
        ++deg[u];
        ++deg[v];
    }
    for (int u = 1; u <= 500; u++) {
        sort(e[u].begin(), e[u].end());
    }
    for (int u = 1; u <= 500; u++) {
        for (Edge& w : e[u]) {
            w.rev = revtop[w.to];
            ++revtop[w.to];
        }
    }
    int start = 1;
    for (int u = 1; u <= 500; u++) {
        if (deg[u] % 2 == 1) {
            start = u;
            break;
        }
    }
    Hierholzer(start);
    for (int i = iCyc; i >= 1; i--) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
