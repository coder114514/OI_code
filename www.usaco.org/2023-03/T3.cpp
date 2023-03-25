#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int L = 3e5 + 10;

string str;
const string bessie = "bessie"; 
// int cnt[L][256]; // not effective

int B(int l, int r) {
    int j = 0;
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (str[i] == bessie[j]) {
            ++j;
            if (j == 6) {
                j = 0;
                res++;
            }
        }
    }
    return res;
}

void BF() {
    // for (int i = 0; i < str.size(); i++) {
    //     cnt[i+1][str[i]]++;
    // }
    // for (int i = 1; i < str.size(); i++) {
    //     for (char c = 'a'; c <= 'z'; c++) {
    //         cnt[i+1][c] += cnt[i][c];
    //     }
    // }
    int ans = 0;
    for (int len = 6; len <= str.size(); len++) {
        for (int i = 0, j = len - 1; j < str.size(); i++, j++) {
            // if (cnt[j+1]['b'] - cnt[i]['b'] >= 1 && cnt[j+1]['i'] - cnt[i]['i'] >= 1 && cnt[j+1]['s'] - cnt[i]['s'] >= 2 && cnt[j+1]['e'] - cnt[i]['e'] >= 2)
            ans += B(i, j);
        }
    }
    cout << ans << endl;
}

// void bruh() { // just wrong
//     int anchor_l = 0;
//     bool l_anchored = false;
//     int j = 0;
//     int ans = 0;
//     for (int i = 0; i < str.size(); i++) {
//         if (!l_anchored) {
//             int k = i;
//             while (k < str.size() && str[k] == 'b') ++k;
//             if (k == str.size()) break;
//             k--;
//             if (k >= i && str[k] == 'b') l_anchored = true, j = 1, anchor_l = k;
//             if (k >= i) i = k;
//             continue;
//         }
//         if (str[i] == bessie[j]) {
//             ++j;
//             if (j == 6) {
//                 j = 0;
//                 l_anchored = false;
//                 int l = anchor_l;
//                 int r = i;
//                 ans += (l + 1) * (str.size() - r);
//             }
//         }
//     }
//     cout << ans << endl;
// }

void bruh2() {
    ll ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ll k = 0, cnt = 0;
        for (int j = i; j < str.size(); j++) {
            if (str[j] == bessie[k]) {
                ++k;
                if (k == 6) {
                    k = 0;
                    cnt++;
                }
            }
            ans += cnt;
        }
    }
    cout << ans << endl;
}

void bruh3() {
    ll ans = 0, last_sum = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != 'b') {
            ans += last_sum;
            continue;
        }
        ll k = 0, sum = 0, cnt = 0;
        for (int j = i; j < str.size(); j++) {
            if (str[j] == bessie[k]) {
                ++k;
                if (k == 6) {
                    k = 0;
                    cnt++;
                }
            }
            sum += cnt;
        }
        last_sum = sum;
        ans += sum;
        // cout << sum << " " << str[i] << endl;
    }
    cout << ans << endl;
}

ll f[L];
int nxt_b[L];

void bruh4() {
    int nxtB = str.size();
    for (int i = str.size() - 1; i >= 0; i--) {
        nxt_b[i] = nxtB;
        if (str[i] == 'b') nxtB = i;
    }
    ll ans = 0, last_sum = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != 'b') {
            ans += last_sum;
            continue;
        }
        ll k = 0, sum = 0, cnt = 0;
        for (int j = i; j < str.size(); j++) {
            if (str[j] == bessie[k]) {
                ++k;
                if (k == 6) {
                    k = 0;
                    cnt++;
                    sum += f[nxt_b[j]] + cnt * (str.size() - j);
                    break;
                }
            }
        }
        f[i] = sum;
        last_sum = sum;
        ans += sum;
    }
    cout << ans << endl;
}

int main() {
    cin >> str;
    bruh4();
    return 0;
}
