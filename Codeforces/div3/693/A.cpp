#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    int ans = 1;
    while (w % 2==0) {
        ans *= 2;
        w >>= 1;
    }
    while (h % 2==0) {
        ans *= 2;
        h >>= 1;
    }
    if (n <= ans)
        cout << Y << endl;
    else
        cout << N << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}