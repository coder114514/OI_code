/*
ID: 18817371
LANG: C++11
PROB: msquare
*/
#include <bits/stdc++.h>
using namespace std;

int target;

int A(int state) {
    int newState = 0;
    while (state) {
        newState = newState * 10 + state % 10;
        state /= 10;
    }
    return newState;
}

int B(int state) {
    int top = state / 10000;
    int bot = state % 10000;
    int x = top % 10;
    top = top / 10 + x * 1000;
    x = bot / 1000;
    bot = bot * 10 % 10000 + x;
    return top * 10000 + bot;
}

int C(int state) {
    int top = state / 10000;
    int bot = state % 10000;
    int a1 = top / 100 % 10;
    int a2 = top / 10 % 10;
    int a3 = bot / 100 % 10;
    int a4 = bot / 10 % 10;
    top = top - a1 * 100 + a4 * 100;
    top = top - a2 * 10 + a1 * 10;
    bot = bot - a3 * 100 + a2 * 100;
    bot = bot - a4 * 10 + a3 * 10;
    return top * 10000 + bot;
}

struct State {
    int step, state;
    string steps;
};

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    // int x = 12345678;
    // cout << A(x) << endl;
    // cout << B(x) << endl;
    // cout << C(x) << endl;
    // return 0;
    for (int i = 1; i <= 8; i++) {
        int x;
        cin >> x;
        target = target * 10 + x;
    }
    queue<State> q;
    map<int, bool> vis;
    q.push(State{0, 12345678});
    while (!q.empty()) {
        State x = q.front(); q.pop();
        if (vis[x.state]) continue;
        vis[x.state] = true;
        if (x.state == target) {
            cout << x.step << endl;
            cout << x.steps << endl;
            return 0;
        }
        q.push(State{x.step+1, A(x.state), x.steps+'A'});
        q.push(State{x.step+1, B(x.state), x.steps+'B'});
        q.push(State{x.step+1, C(x.state), x.steps+'C'});
    }
    return 0;
}
