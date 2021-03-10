#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

const string A = "Alice";
const string B = "Bob";
const string T = "Tie";

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll ascore = 0, bscore = 0;
    while (a.size()) {
        int m = a.back();
        if (m % 2 == 0)
            ascore += m;
        a.pop_back();
        if (a.empty())
            break;
        m = a.back();
        if (m % 2 != 0)
            bscore += m;
        a.pop_back();
    }
    if (ascore > bscore)
        cout << A;
    else if (bscore > ascore)
        cout << B;
    else
        cout << T;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}