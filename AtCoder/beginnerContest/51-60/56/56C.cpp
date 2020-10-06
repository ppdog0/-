// 1+2+...+t >= X
// (1+t)t/2 >= X
// (1+t)t >= 2*X

#include<iostream>

using namespace std;
typedef long long ll

int main() {
    ll X;
    ll ans = 0;
    cin >> X;

    while(true) {
        if(ans*ans + ans >= 2*X) {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }

    return 0;
}
