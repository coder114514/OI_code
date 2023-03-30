#include <bits/stdc++.h>
using namespace std;

// max - min == k * (r - l)，线段树维护区间最大最小
// 差分数组 [l, r] gcd 为 k 的倍数，线段树维护区间gcd // 似乎gcd只可能是k
// 没有重复数字，维护前驱，用set找前驱，用线段树维护区间最大前驱

inline int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

const int N = 3e5 + 1;

#define ls(u) (u * 2)
#define rs(u) (u * 2 + 1)

struct Seg {
    int l, r;
    int mx, mn;
    int pre;
    int gcd;
} tr[N * 4];

int a[N], pre[N];

Seg merge(const Seg& a, const Seg& b) {
    Seg res;
    res.l = a.l, res.r = b.r;
    res.mx = max(a.mx, b.mx);
    res.mn = min(a.mn, b.mn);
    res.pre = max(a.pre, b.pre);
    res.gcd = gcd(a.gcd, b.gcd);
    return res;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = Seg{l, r, a[l], a[l], pre[l], abs(a[l] - a[l - 1])};
        return;
    }
    int mid = l + (r - l) / 2;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    tr[u] = merge(tr[ls(u)], tr[rs(u)]);
}

// a[x]变成y
void update_mnmx(int u, int& x, int& y) {
    if (tr[u].l == tr[u].r) {
        tr[u].mx = y;
        tr[u].mn = y;
        return;
    }
    if (x <= tr[ls(u)].r) update_mnmx(ls(u), x, y);
    else update_mnmx(rs(u), x, y);
    tr[u].mx = max(tr[ls(u)].mx, tr[rs(u)].mx);
    tr[u].mn = min(tr[ls(u)].mn, tr[rs(u)].mn);
}

// d[x]变成z
void update_d(int u, const int& x, const int& z) {
    if (tr[u].l == tr[u].r) {
        tr[u].gcd = z;
        return;
    }
    if (x <= tr[ls(u)].r) update_d(ls(u), x, z);
    else update_d(rs(u), x, z);
    tr[u].gcd = gcd(tr[ls(u)].gcd, tr[rs(u)].gcd);
}

// 更新 pre[x]
void update_pre(int u, const int& x) {
    if (tr[u].l == tr[u].r) {
        tr[u].pre = pre[x];
        return;
    }
    if (x <= tr[ls(u)].r) update_pre(ls(u), x);
    else update_pre(rs(u), x);
    tr[u].pre = max(tr[ls(u)].pre, tr[rs(u)].pre);
}

Seg query(int u, const int& l, int& r) {
    if (r < tr[u].l || l > tr[u].r) {
        Seg res{0, 0, 0, (int)1e9, 0, 0};
        return res;
    }
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u];
    }
    Seg resL = query(ls(u), l, r);
    Seg resR = query(rs(u), l, r);
    return merge(resL, resR);
}

int n, m, ans;
map<int, set<int>> rmap;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!rmap.count(a[i])) {
            rmap[a[i]] = set<int>();
        }
        else {
            auto it = rmap[a[i]].end();
            pre[i] = *--it;
        }
        rmap[a[i]].insert(i);
    }
    build(1, 1, n);
    for (int iQ = 1; iQ <= m; iQ++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            x ^= ans;
            y ^= ans;
            auto it = rmap[a[x]].upper_bound(x);
            if (it != rmap[a[x]].end()) { // 更新后继
                pre[*it] = pre[x];
                update_pre(1, *it);
            }
            rmap[a[x]].erase(x);
            ///////////////////////
            update_d(1, x, abs(y - a[x - 1]));
            update_d(1, x + 1, abs(a[x + 1] - y));
            ///////////////////////
            if (!rmap.count(y)) { // 值域上的新值
                rmap[y] = set<int>();
                rmap[y].insert(x);
                pre[x] = 0;
                update_pre(1, x);
            }
            else { // 已经有过这个值了
                it = rmap[y].upper_bound(x); // 新后继
                if (it == rmap[y].begin()) { // 无前驱
                    pre[*it] = x;
                    pre[x] = 0;
                }
                else if (it == rmap[y].end()) { // 无后继
                    --it;
                    pre[x] = *it;
                }
                else { // 有前驱有后继
                    pre[x] = pre[*it];
                    pre[*it] = x;
                }
                update_pre(1, x);
                if (it != rmap[y].end()) update_pre(1, *it);
                rmap[y].insert(x);
            }
            a[x] = y;
            update_mnmx(1, x, y);
        }
        else {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            l ^= ans;
            r ^= ans;
            k ^= ans;
            if (l == r) {
                printf("Yes\n");
                ans++;
                continue;
            }
            Seg res = query(1, l, r);
            Seg res_gcd = query(1, l + 1, r);
            if (res.mx - res.mn == 1LL * k * (r - l) && (res.pre < l || k == 0) && (res_gcd.gcd == k || k == 0)) { // 特判 k == 0
                printf("Yes\n");
                ans++;
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}
