#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll V = 50010;
const ll E = 100010;
const short WHITE = 0;
const short BLACK = 1;

ll n, m, k;

struct Edge {
    ll u, v, w;
} e[2][E];
ll num[2];

bool operator<(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

ll id[V];

void init() {
    for (ll i = 1; i <= n; i++) {
        id[i] = i;
    }
}

ll find(ll u) {
    return id[u] = (id[u] == u ? u : find(id[u]));
}

void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    id[x] = y;
}

struct Opt {
    ll val, cnt;
};

Opt kruskal(ll cpu) {
    ll val = 0;
    ll cUsed[2] = {0, 0};
    ll i[2] = {1, 1};
    init();
    do {
        ll clr;
        if (i[BLACK] > num[BLACK]) clr = WHITE;
        else if (i[WHITE] > num[WHITE]) clr = BLACK;
        //同边权值时优先选白色，如果尽量选了白色后白边数>=k，说明白边数能取到k，应该加入可能的解的范围，否则就是取不到k，应该排除在可能的解的范围外
        else if (e[WHITE][i[WHITE]].w + cpu <= e[BLACK][i[BLACK]].w) clr = WHITE;
        else clr = BLACK;
        ll u = e[clr][i[clr]].u;
        ll v = e[clr][i[clr]].v;
        ll w = e[clr][i[clr]].w;
        ++i[clr];
        ll ru = find(u);
        ll rv = find(v);
        if (ru == rv) continue;
        merge(u, v);
        ++cUsed[clr];
        val += w;
        if (clr == WHITE) val += cpu;
    } while (cUsed[WHITE] + cUsed[BLACK] < n - 1);
    return (Opt){val, cUsed[WHITE]};
}

int main() {
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ++a;
        ++b;
        e[d][++num[d]] = (Edge){a, b, c};
    }
    sort(e[BLACK] + 1, e[BLACK] + 1 + num[BLACK]);
    sort(e[WHITE] + 1, e[WHITE] + 1 + num[WHITE]);
    ll l = -5000000;
    ll r = 5000000;
    ll bestCpu;
    while (l <= r) {
        ll mid = (l + r) / 2;
        Opt opt = kruskal(mid);
        if (opt.cnt >= k) {
            l = mid + 1;
            bestCpu = mid;
        }
        else {
            r = mid - 1;
        }
    }
    ll ans = kruskal(bestCpu).val - bestCpu * k;
    cout << ans << endl;
    return 0;
}
