#include<iostream>

using namespace std;

long long a, b, x;

int main() {
    cin >> a >> b >> x;
    long long ans = ((b / x) + 1) - ((a - 1) < 0 ? 0 : (a - 1) / x + 1);
    cout << ans << endl;
    return 0;
}