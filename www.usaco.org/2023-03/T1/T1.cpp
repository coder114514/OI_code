#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 150010;

ll n, a[N];

ll b[N];
// O(Q*N*logN)
void BF() {
    ll Q;
    cin >> Q;
    for (ll iQ = 1; iQ <= Q; iQ++) {
        ll i, j;
        scanf("%lld%lld", &i, &j);
        ll tmp = a[i];
        a[i] = j;
        memcpy(b, a, sizeof(b));
        sort(b + 1, b + n + 1);
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans += b[i] * i;
        }
        printf("%lld\n", ans);
        a[i] = tmp;
    }
}

// mp: 每个元素排序之后去哪里了
// mp2: 排序之后每个值的下标
map<ll, ll> mp2;
ll mp[N], s[N];
pair<ll, ll> c[N];
set<ll> S;
void solve() {
    for (int i = 1; i <= n; i++) {
        c[i].first = a[i];
        c[i].second = i;
        S.insert(a[i]);
    }
    ll ans = 0;
    sort(c + 1, c + n + 1);
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) mp2[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        mp[c[i].second] = i;
        s[i] = s[i - 1] + a[i];
        ans += a[i] * i;
        // cout << i << "," << a[i] << endl;
    }
    // for (int i = 1; i <= n; i++) cout << "mp[" << i << "]: " << mp[i] << endl;
    ll Q;
    cin >> Q;
    for (ll iQ = 1; iQ <= Q; iQ++) {
        ll i, j;
        scanf("%lld%lld", &i, &j);
        i = mp[i];
        ll ans1 = ans - a[i] * i;
        S.erase(a[i]);
        auto it = S.lower_bound(j);
        ll idx = (it == S.end() ? n + 1 : mp2[*it]);
        // cout << "deb: " << i << " " << j << " " << idx << endl;
        if (idx <= i) {
            ans1 += s[i - 1] - s[idx - 1];
            ans1 += j * idx;
        }
        else {
            ans1 -= s[idx - 1] - s[i];
            ans1 += j * (idx - 1);
        }
        printf("%lld\n", ans1);
        S.insert(a[i]);
    }
}

int main() {
    // freopen("T1in.txt", "r", stdin);
    // freopen("T1out.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    solve();
    return 0;
}
