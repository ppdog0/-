#include <iostream>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int count(int x) {
    int res = 0;
    while(x) {
        x /= 10;
        res++;
    }
    return res;
}

int mul(int x, int k) {
    int res = 1;
    for (int i = 0; i < k; i++) {
        res *= 10;
    }
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int la = mul(1, a), lb = mul(1, b);
    for (int x = mul(1,a-1); x < la; x++) {
        for (int y = mul(1,b-1); y < lb; y++) {
            if (count(gcd(x,y)) == c) {
                cout << x << " " << y << endl;
                return;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}