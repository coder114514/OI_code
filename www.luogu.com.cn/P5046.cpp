#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace io {
    const int SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // print the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed integer
    template <class I>
    inline void gi (I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    // print a signed integer
    template <class I>
    inline void print (I x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;

const int N = 1e5 + 9;
const int NB = 709;

int n, m, x[N], y[N], id[N];
// pre[x]：x到它所在块块首的区间内的逆序对数量
// suf[x]: x到它所在块块尾的区间内的逆序对数量
// F[i][j]: 块i到块j的这段区间内的逆序对数量
// f[i][j]: a1-aj与第i块中的数形成的逆序对数量
int pre[N], suf[N], f[NB][N];
ll F[NB][NB], ans;
// 分块
int bel[N], L[NB], R[NB], bSize;
///////////////////////BIT
int bit[N];

inline void add(int p, int d) {
    for (int i = p; i <= n; i += i & -i)
        bit[i] += d;
}

inline int psq(int p) {
    int sum = 0;
    for (int i = p; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}
////////////////////////////
int a[N], b[N], la, lb;
inline int merge(int *a, int *b, int la, int lb) {
    int ia = 1, ib = 1;
    int res = 0;
    while (ia <= la && ib <= lb) {
        if (a[ia] < b[ib])
            ++ia;
        else
            res += la - ia + 1, ++ib;
    }
    return res;
}
////////////////////////////
inline void init() {
    /////////分块
    bSize = 370;
    for (int i = 1; i <= n; i++)
        bel[i] = (i - 1) / bSize + 1;
    for (int i = 1; i <= bel[n]; i++) {
        L[i] = R[i - 1] + 1;
        R[i] = i * bSize;
    }
    R[bel[n]] = n;
    ////////算pre和suf,块内排序
    for (int i = 1; i <= bel[n]; i++) {
        sort(y + L[i], y + R[i] + 1);
        int nrp = 0;
        for (int j = L[i]; j <= R[i]; j++) {
            add(x[j], 1);
            nrp += j - L[i] + 1 - psq(x[j]);
            pre[j] = nrp;
        }
        F[i][i] = nrp;
        for (int j = L[i]; j <= R[i]; j++) {
            suf[j] = nrp;
            add(x[j], -1);
            nrp -= psq(x[j] - 1);
        }
    }
    /////////////计算f
    for (int i = 1; i <= bel[n]; i++) {
        int k = L[i];
        for (int j = 1; j <= n; j++) {
            while (k <= R[i] && y[k] < j) ++k;
            if (id[j] < L[i]) {
                f[i][id[j]] = k - L[i];
            }
            else if (id[j] > R[i]) {
                f[i][id[j]] = R[i] - k + 1;
            }
        }
        for (int j = 1; j <= n; j++) {
            f[i][j] += f[i][j-1];
        }
    }
    /////////////计算F
    for (int k = 1; k < bel[n]; k++) {
        for (int i = 1; i + k <= bel[n]; i++) {
            const int j = i + k;
            F[i][j] = F[i+1][j] + F[i][j-1] - F[i+1][j-1] + f[j][R[i]] - f[j][L[i]-1];
        }
    }
}
/////////////////////
inline void solve(int l, int r) {
    int bL = bel[l], bR = bel[r];
    if (bL == bR) {
        la = lb = 0;
        for (int i = L[bL]; i <= R[bL]; i++) {
            if (id[y[i]] >= l && id[y[i]] <= r)
                b[++lb] = y[i];
            else if (id[y[i]] < l)
                a[++la] = y[i];
        }
        ans = pre[r] - (l == L[bL] ? 0 : pre[l-1]) - merge(a, b, la, lb);
    }
    else {
        ans = F[bL+1][bR-1] + pre[r] + suf[l];
        for (int i = bL + 1; i <= bR - 1; i++) {
            ans += f[i][R[bL]] - f[i][l-1] + f[i][r] - f[i][L[bR]-1];
        }
        la = lb = 0;
        for (int i = L[bL]; i <= R[bL]; i++) {
            if (id[y[i]] >= l)
                a[++la] = y[i];
        }
        for (int i = L[bR]; i <= R[bR]; i++) {
            if (id[y[i]] <= r)
                b[++lb] = y[i];
        }
        ans += merge(a, b, la, lb);
    }
    print(ans);
    putc('\n');
}

int main() {
    gi(n);
    gi(m);
    for (int i = 1; i <= n; i++) {
        gi(y[i]);
        x[i] = y[i];
        id[x[i]] = i;
    }
    init();
    for (int i = 1; i <= m; i++) {
        ll l, r;
        ll in1, in2;
        gi(in1); gi(in2);
        l = in1 ^ ans;
        r = in2 ^ ans;
        solve(l, r);
    }
    return 0;
}
