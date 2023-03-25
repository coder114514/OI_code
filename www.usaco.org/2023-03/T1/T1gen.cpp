#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("T1in.txt", "w", stdout);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distN(1, 100);
    int n = distN(rng);
    cout << n << endl;
    std::uniform_int_distribution<std::mt19937::result_type> distA(1, 100);
    for (int i = 1; i <= n; i++) {
        cout << distA(rng) << " ";
    }
    cout << endl;
    int Q = distN(rng);
    cout << Q << endl;
    for (int iQ = 1; iQ <= Q; iQ++) {
        std::uniform_int_distribution<std::mt19937::result_type> distN(1, n);
        cout << distN(rng) << " " << distA(rng) << endl;
    }
    return 0;
}
