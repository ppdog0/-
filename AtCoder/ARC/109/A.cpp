#include<iostream>

using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;
    int ans = 0;
    int m = min(2 * x, y);
    ans += (abs(a - b) - 1) * m;
    if (a == b) {
        ans = x;
    } else if (b < a) {
        ans += x;
    } else if (a < b) {
        ans += min(3 * x, x + y);
    }
    cout << ans << endl;
}