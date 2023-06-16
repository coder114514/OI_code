#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, a[N];
ll m, nSeg[N];        // nSeg[l]: 长度为l的区间有几个
vector<int> where[N]; // where[x]:数字x出现在a数组的哪些位置中

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 1; i <= n; i++) where[i].clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            where[a[i]].push_back(i);
        }
        cin >> m;
        memset(nSeg, 0, sizeof(nSeg));
        nSeg[n] = n;
        set<int> black = {0, n + 1};  // 当前行所有黑块
        for (int i = n; i > 0; i--) { // O(nlogn)
            for (int x : where[i]) {
                // x:新增的黑块的位置
                int L = *prev(black.lower_bound(x)); // x前的黑块
                int R = *black.upper_bound(x);       // x后的黑块
                // 区间[L+1,R-1]被分开来了
                nSeg[R - L - 1] -= i;
                nSeg[R - x - 1] += i;
                nSeg[x - L - 1] += i;
                black.insert(x);
            }
        }
        ll ans = 0;
        for (int len = n; len > 0; len--) { // O(n)
            if (m == 0) break;
            ll cnt = min(nSeg[len], m / len);
            ans += (len - 1) * cnt;
            m -= len * cnt;
            if (cnt != nSeg[len] && m) {
                ans += m - 1;
                m = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
