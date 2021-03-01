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