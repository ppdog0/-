#include<iostream>
#include<cmath>

using namespace std;

int t, n, x;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> x;
        int ans = (n <= 2) ? 1 : ceil((float)(n - 2) / x) + 1;
        cout << ans << endl;
    }
}