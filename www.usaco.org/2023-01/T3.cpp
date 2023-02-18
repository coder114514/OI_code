#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, a[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    string route;
    int i = 0;
    while (i || a[i]) {     //不在起点或者还没走完
        while (a[i] > 0) {
            a[i]--; i++;
            route += 'R';
        }
        while (i && (a[i-1] > 1 || a[i] == 0)) {
            i--; a[i]--;
            route += 'L';
        }
    }
    cout << route << endl;
    return 0;
}
