#include<iostream>

using namespace std;

long long x, Y, A, B;

int main() {
    cin >> x >> Y >> A >> B;
    long long ans = 0;
    while ( (double)A * x <= 2e18 && (A * x < Y) && (A * x <= x + B)) {
        x *= A;
        ans++;
    }
    cout << ans + (Y - x - 1) / B << endl;
}