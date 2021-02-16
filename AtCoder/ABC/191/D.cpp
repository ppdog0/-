#include<iostream>
#include<cmath>

using namespace std;
const int scale = 1e4;

long long x, y, r;

int in() {
    double x;
    cin >> x;
    x *= scale;
    return round(x);
}

bool ok(long long dx, long long dy, long long r) {
    return dx * dx + dy * dy <= r * r;
}

long long f(int x, int y, int r, int limit) {
    int l = 0, r = 1;
    long long res = 0;
    for (int i = 1e9; limit <= i; i -= scale) {
        while(ok(x - l*scale, y - i, r))
            --l;
        while(ok(x - r*scale, y - i, r))
            ++r;
        res += r - l - 1;
    }
    return res;
}

int main() {
    x = in();
    y = in();
    r = in();
    x %= scale; // 小数点后四位
    y %= scale;

    cout << f(x, y, r, scale) + f(x, -y, r, 0) << endl;
}

// // D - Circle Lattice Points
// #include <bits/stdc++.h>
// using namespace std;
// using ll = int64_t;

// int scale = 1e4;

// int in()
// {
//     double x;
//     cin >> x;
//     return round(x * scale);
// }
// bool ok(ll dx, ll dy, ll r) { return dx * dx + dy * dy <= r * r; }

// ll f(int x, int y, int r, int limit)
// {
//     int L = 0, R = 1;
//     ll res = 0;
//     for (int i = 1e9 + scale * 5; i >= limit; i -= scale)
//     {
//         while (ok(x - L * scale, y - i, r))
//             L--;
//         while (ok(x - R * scale, y - i, r))
//             R++;
//         res += R - (L + 1);
//     }
//     return res;
// }

// int main()
// {
//     int x = in(), y = in(), r = in();
//     x %= scale, y %= scale;
//     cout << f(x, y, r, scale) + f(x, -y, r, 0) << endl;
// }
