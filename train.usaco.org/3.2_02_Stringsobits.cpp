/*
ID: 18817371
LANG: C++11
PROB: kimbits
*/
#include <bits/stdc++.h>
using namespace std;

unsigned int N, L, I;
unsigned int C[35][35];

int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    cin >> N >> L >> I;
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= N; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    string ans;
    for (int i = 1; i <= N; i++) {
        int x = 0;
        for (int j = 0; j <= L; j++) {
            x += C[N-i][j];
        }
        if (I <= x) {
            ans += '0';
        }
        else {
            ans += '1';
            I -= x;
            --L;
        }
    }
    cout << ans << endl;
    return 0;
}
