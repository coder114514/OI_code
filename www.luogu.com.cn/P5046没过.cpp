// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') { // ch 不是数字时
        if (ch == '-')
            w = -1;     // 判断是否为负
        ch = getchar(); // 继续读入
    }
    while (ch >= '0' && ch <= '9') { // ch 是数字时
        x = x * 10 + (ch - '0');     // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar(); // 继续读入
    }
    return x * w; // 数字 * 正负号 = 实际数值
}

const int N = 1e5 + 9;
const int NB = 709;

int n, m, x[N], y[N], id[N];
// pre[x]：x到它所在块块首的区间内的逆序对数量
// suf[x]: x到它所在块块尾的区间内的逆序对数量
// F[i][j]: 块i到块j的这段区间内的逆序对数量
// cnt[i][j]: 前i块中小于等于j的元素数量
ll pre[N], suf[N], F[NB][NB], cnt[NB][N], ans;
// 分块
int bel[N], L[NB], R[NB], bSize;
///////////////////////BIT
int bit[N];

void clear_bit() {
    memset(bit, 0, sizeof(bit));
}

void add(int p, int d) {
    for (int i = p; i <= n; i += i & -i)
        bit[i] += d;
}

int psq(int p) {
    int sum = 0;
    for (int i = p; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}
////////////////////////////
int a[N], b[N], la, lb;
ll merge(int *a, int *b, int la, int lb) {
    int ia = 1, ib = 1;
    ll res = 0;
    while (ia <= la && ib <= lb) {
        if (a[ia] < b[ib])
            ++ia;
        else
            res += la - ia + 1, ++ib;
    }
    return res;
}
////////////////////////////
void init() {
    /////////分块
    bSize = n / (sqrt(m) + 1) + 1;
    for (int i = 1; i <= n; i++)
        bel[i] = (i - 1) / bSize + 1;
    for (int i = 1; i <= bel[n]; i++) {
        L[i] = R[i - 1] + 1;
        R[i] = i * bSize;
    }
    R[bel[n]] = n;
    ////////算pre和suf,块内排序
    for (int i = 1; i <= bel[n]; i++) {
        memcpy(cnt[i], cnt[i - 1], sizeof(cnt[0]));
        sort(y + L[i], y + R[i] + 1);
        ll nrp = 0;
        clear_bit();
        for (int j = L[i]; j <= R[i]; j++) {
            cnt[i][x[j]]++;
            add(x[j], 1);
            nrp += psq(n) - psq(x[j]);
            pre[j] = nrp;
        }
        F[i][i] = nrp;
        nrp = 0;
        clear_bit();
        for (int j = R[i]; j >= L[i]; j--) {
            add(x[j], 1);
            nrp += psq(x[j] - 1);
            suf[j] = nrp;
        }
    }
    /////////////计算cnt
    for (int i = 1; i <= bel[n]; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    /////////////计算F
    for (int k = 1; k < bel[n]; k++) {
        for (int i = 1; i <= bel[n]; i++) {
            if (i + k > bel[n])
                break;
            int j = i + k;
            F[i][j] = F[i + 1][j] + F[i][j - 1] - F[i + 1][j - 1] + merge(y + L[i] - 1, y + L[j] - 1, R[i] - L[i] + 1, R[j] - L[j] + 1);
        }
    }
}
/////////////////////
ll solve(int l, int r) {
    if (bel[l] == bel[r]) {
        la = lb = 0;
        for (int i = L[bel[l]]; i <= R[bel[l]]; i++) {
            if (id[y[i]] >= l && id[y[i]] <= r)
                b[++lb] = y[i];
            else if (id[y[i]] < l)
                a[++la] = y[i];
        }
        ans = pre[r] - (l == L[bel[l]] ? 0 : pre[l - 1]) - merge(a, b, la, lb);
        return ans;
    }
	else {
        ans = F[bel[l] + 1][bel[r] - 1] + pre[r] + suf[l];
        for (int i = l; bel[i] == bel[l]; i++) // 统计x[i]>块中的
        {
            ans += cnt[bel[r] - 1][x[i] - 1] - cnt[bel[l]][x[i] - 1];
        }
        for (int i = r; bel[i] == bel[r]; i--) // 统计x[i]<块中的
        {
            ans += cnt[bel[r] - 1][n] - cnt[bel[l]][n] - cnt[bel[r] - 1][x[i]] + cnt[bel[l]][x[i]];
        }
        la = lb = 0;
        for (int i = L[bel[l]]; i <= R[bel[l]]; i++) {
            if (id[y[i]] >= l)
                a[++la] = y[i];
        }
        for (int i = L[bel[r]]; i <= R[bel[r]]; i++) {
            if (id[y[i]] <= r)
                b[++lb] = y[i];
        }
        ans += merge(a, b, la, lb);
        return ans;
    }
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
        y[i] = x[i] = read(), id[x[i]] = i;
    init();
    for (int i = 1; i <= m; i++) {
        ll l, r;
        l = read() ^ ans;
        r = read() ^ ans;
        printf("%lld\n", solve(l, r));
    }
    return 0;
}
