#include <bits/stdc++.h>
using namespace std;

const int N = 1048576 * 2 + 5;

complex<double> a[N], b[N];
int ans[N];
int L;
char strA[1000005], strB[1000005];
int rev[N];

const double PI = acos(-1);

void init(int len) {
    rev[0] = 0;
    for (int i = 1; i < len; i++) {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= (len >> 1);
    }
}

void butterfly(complex<double>* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i < rev[i]) {
            swap(arr[i], arr[rev[i]]);
        }
    }
}

void FFT(complex<double>* y, int len, int on) {
    butterfly(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        complex<double> wn(cos(2 * PI / h), sin(2 * PI / h * on));
        for (int i = 0; i < len; i += h) {
            complex<double> w(1, 0);
            for (int j = i; j < i + h / 2; j++) {
                complex<double> u = y[j];
                complex<double> t = w * y[j + h / 2];
                y[j] = u + t;
                y[j + h / 2] = u - t;
                w *= wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; i++) {
            y[i] /= len;
        }
    }
}

int main() {
    scanf("%s%s", strA, strB);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    for (int i = 0; i < lenA; i++) {
        a[lenA - i - 1] = strA[i] - '0';
    }
    for (int i = 0; i < lenB; i++) {
        b[lenB - i - 1] = strB[i] - '0';
    }
    L = 1;
    while (L < lenA + lenB) {
        L <<= 1;
    }
    init(L);
    FFT(a, L, 1);
    FFT(b, L, 1);
    for (int i = 0; i < L; i++) {
        a[i] *= b[i];
    }
    FFT(a, L, -1);
    for (int i = 0; i < L; i++) {
        ans[i] += (int)(a[i].real() + 0.5);
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (!ans[L] && L > 0) {
        --L;
    }
    for (int i = L; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
