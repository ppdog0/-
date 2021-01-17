#include<iostream>
#include<cmath>

using namespace std;

long long N;
int M;

long long mod_pow(int x, long long n, int mod) {
    long long res = 1, ret = x % mod;
    while(n) {
        if (n & 1)
            res = res * ret % mod;
        ret = ret * ret % mod;
        n >>= 1LL;
    }
    return res;
}

int main() {
    cin >> N >> M;
    cout << (mod_pow(10, N, M * M) / M) % M << endl;
}