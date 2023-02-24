/*
ID: 18817371
LANG: C++11
PROB: ratios
*/
#include <bits/stdc++.h>
using namespace std;

int ga, gb, gc;
int a1, b1, c1;
int a2, b2, c2;
int a3, b3, c3;

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    cin >> ga >> gb >> gc;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> a3 >> b3 >> c3;
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            for (int z = 0; z <= 100; z++) {
                if (!(x || y || z)) continue;
                int a = x*a1+y*a2+z*a3;
                int b = x*b1+y*b2+z*b3;
                int c = x*c1+y*c2+z*c3;
                if ((ga && (a % ga)) || (gb && (b % gb)) || (gc && (c % gc))) continue;
                if (a * gb == b * ga && b * gc == c * gb) {
                    cout << x << " " << y << " " << z << " " << a/ga << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NONE" << endl;
    return 0;
}
