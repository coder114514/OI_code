#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int nC, n;
string team[N];
bool table[1 << 18];
vector<int> team_num;
int ans_for_team[1 << 18];

int diff(const string& a, const string& b) {
    int res = 0;
    for (int i = 0; i < nC; i++) {
        res += (a[i] != b[i]);
    }
    return res;
}

int diff(int a, int b) {
    int c = a ^ b;
    int res = 0;
    while (c) {
        res++;
        c -= c & -c;
    }
    return res;
}

int to_num(const string& s) {
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            x |= (1 << i);
        }
    }
    return x;
}

void BF() {
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            ans = max(ans, diff(team[i], team[j]));
        }
        cout << ans << endl;
    }
}

void BF2() {
    for (int x : team_num) {
        for (int y : team_num) {
            if (x != y) {
                ans_for_team[x] = max(ans_for_team[x], diff(x, y));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans_for_team[to_num(team[i])] << endl;
    }
}

bool enum_combo(int i, int k) {
    int combo = (1 << k) - 1;
    while (combo < (1 << 18)) {
        if (table[combo ^ to_num(team[i])]) return true;
        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }
    return false;
}

void BF3() {
    for (int i = 1; i <= n; i++) {
        int d = nC;
        while (!enum_combo(i, d)) --d;
        cout << d << endl;
    }
}

int main() {
    cin >> nC >> n;
    for (int i = 1; i <= n; i++) {
        cin >> team[i];
        table[to_num(team[i])] = true;
    }
    for (int x = 0; x < (1 << 18); x++) {
        if (!table[x]) continue;
        team_num.push_back(x);
    }
    if (n * team_num.size() <= 1e8) {
        BF2();
    }
    else {
        BF3();
    }
    return 0;
}
