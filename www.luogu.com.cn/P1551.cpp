#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, m, p;

int f[N];

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    else {
        return f[x] = find(f[x]);
    }
}

void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    f[a] = b;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (find(x) == find(y)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
