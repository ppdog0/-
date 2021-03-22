#include<iostream>

using namespace std;
using ll = long long;

// 阶
ll fast_pow(int n, int k)
{
    ll res = 1;
    while (k) {
        if (k & 1) {
            res *= n;
        }
        n *= n;
        k >>= 1;
    }
    return res;
}

// 阶层
ll fact(int n) {
    ll res = 1;
    while (n) {
        res *= n;
        n--;
    }
    return res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(int a, int b) {
    return a / gcd(a, b) * 1ll * b;
}