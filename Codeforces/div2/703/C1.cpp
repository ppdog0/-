#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int guess (int lo, int hi) {
    int x;
    cout << "? " << lo << " " << hi << endl;
    cin >> x;
    return x;
}

int bin(int lo, int hi) {
    while (1 < hi - lo) {
        int mi = (lo + hi) >> 1;
        int smax = guess(lo, hi);
        if (smax < mi) {
            if (smax == guess(lo, mi))
                hi = mi;
            else
                lo = mi;
        } else {
            if (smax == guess(mi, hi))
                lo = mi;
            else
                hi = mi;
        }
    }
    return lo == guess(lo, hi) ? hi : lo;
}

void solve() {
    int n;
    cin >> n;
    int k = bin(1, n);
    cout << "! " << k << endl;
}

int main() {
    solve();
}

// mi = guess(lo, hi);
// if (mi == lo || mi == hi) {
//     int k;
//     k = (lo + hi) >> 1;
//     x = guess(lo, k);
// } else {0
//     x = guess(lo, mi);
//     if (mi == x) {
//         hi = mi - 1;
//     } else {
//         lo = mi + 1;
//     }
// }