#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int sum1 = 0, sum2 = 0;
    int c1 = 0, c2 = 0;
    vector<int> rec;
    for (int i = 0; i < n; i++) {
        int x = a[i] - '0', y = b[i] - '0';
        sum1 += x, sum2 += y;
        if (x == 0) c1++;
        else c2++;
        if (c1==c2) rec.push_back(i);
    }
    if (sum1!=sum2) {
        cout << N << endl;
        return;
    }

    int m = rec.size();
    vector<pair<int,int>> rev;
    int prev = 0;
    for (int i = m-1; 0 <= i; i--) {
        int l, r = rec[i];
        if (i == 0) l = 0;
        else l = rec[i - 1] + 1;

        string s1 = a.substr(l, r-l+1), s2 = b.substr(l, r-l+1);
        if (s1 != s2 && prev%2==0) {
            prev++;
            rev.push_back({r,prev});
        } else if (s1 == s2 && prev%2!=0) {
            prev++;
            rev.push_back({r,prev});
        }
    }

    m = rev.size();
    for (int i = 0; i < m; i++) {
        if(rev[i].second%2==0)
            continue;

        int l, r = rev[i].first;
        if (i == m-1) l = 0;
        else l = rev[i + 1].first + 1;
        for (int j = l; j <= r; j++) {
            a[j] = '0' + (a[j]-'0' + 1) % 2;
        }
    }

    if (a == b) cout << Y << endl;
    else cout << N << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}