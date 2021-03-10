#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve()
{
    int n;
    cin >> n;
    int a=0, b=0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1)
            a++;
        else
            b++;
    }
    if (a%2==0) {
        if ( (a==0 && b%2==0) || (a != 0)) {
            cout << Y << endl;
            return;
        }
    }
    cout << N << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}