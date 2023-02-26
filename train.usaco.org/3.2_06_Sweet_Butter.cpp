/*
ID: 18817371
LANG: C++11
PROB: butter
*/

#include <bits/stdc++.h>
using namespace std;

const int NCOW = 510;
const int NV = 810;
const int NE = 1450*2 + 10;

int nCow, nV, m;
int cows[NCOW];

struct Edge {
    int to, nxt, w;
} e[NE];

int nE, hd[NV];

void add(int u, int v, int w) {
    e[++nE] = Edge{v, hd[u], w};
    hd[u] = nE;
}

typedef pair<int, int> pii;

int dis[NV];
bool vis[NV];

void Dijkstra(int S) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, S));
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = hd[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    cin >> nCow >> nV >> m;
    for (int i = 1; i <= nCow; i++) {
        cin >> cows[i];
    }
    for (int iE = 1; iE <= m; iE++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    int ans = 1 << 30;
    for (int iP = 1; iP <= nV; iP++) {
        Dijkstra(iP);
        int sum = 0;
        for (int i = 1; i <= nCow; i++) {
            sum += dis[cows[i]];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
