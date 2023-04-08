#include <bits/stdc++.h>
using namespace std;

int n, m, x;

struct Interval {
    int l, r;
};

bool cmp1(const Interval&u, const Interval&v) {
    return u.l < v.l;
}

Interval a[200010];
int ans2[200010], cAns2;
int ans1[200010], cAns1;
bool markL[200010], markR[200010];

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
        markL[a[i].l] = true;
        markR[a[i].r] = true;
    }
    sort(a + 1, a + m + 1, cmp1);
    int y = x;
    for (int i = 1; i <= m; i++) {
        if (a[i].l <= y) {
            y = max(y, a[i].r);
        }
    }
    for (int p = x + 1; p <= y; p++) {
        if (markR[p]) {
            ans2[++cAns2] = p;
        }
    }
    y = x;
    for (int i = m; i >= 1; i--) {
        if (a[i].r >= y) {
            y = min(y, a[i].l);
        }
    }
    for (int p = y; p < x; p++) {
        if (markL[p]) {
            ans1[++cAns1] = p;
        }
    }
    for (int i = 1; i <= cAns1; i++) {
        printf("%d ", ans1[i]);
    }
    for (int i = 1; i <= cAns2; i++) {
        printf("%d ", ans2[i]); 
    }
    cout << endl;
    return 0;
}
