#include <iostream>
using namespace std;

int guess (int lo, int hi) {
    int x;
    cout << "? " << lo << " " << hi << endl;
    cin >> x;
    return x;
}

int bin(int lo, int hi) {
    int smax = guess(lo, hi);
    int k;
    if (smax == lo) k = hi;
    else if (smax == hi) k = lo;
    else k = smax == guess(smax, hi) ? hi : lo;

    if (smax < k) {
        lo = smax;
        while (1 < hi - lo) {
            int mi = (lo + hi) >> 1;
            if (smax == guess(smax, mi)) hi = mi;
            else lo = mi;
        }
        return lo == guess(lo, hi) ? hi : lo;
    } else {
        hi = smax;
        while (1 < hi - lo) {
            int mi = (lo + hi) >> 1;
            if (smax == guess(mi, smax)) lo = mi;
            else hi = mi;
        }
        return lo == guess(lo, hi) ? hi : lo;
    }
}

int main() {
    int n;
    cin >> n;
    int k = bin(1, n);
    cout << "! " << k << endl;
}