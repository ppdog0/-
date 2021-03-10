#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
char car[3] = {'a', 'b', 'c'};

int count(string a) {
    int num[a.size()] = {0};
    int x = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'a') {
            x++;
        } else if (a[i] =='b') {
            num[i] = x;
        }
    }
    int res = 0;
    int y = 0;
    for (int j = a.size() - 1; 0 <= j; j--) {
        if (a[j] == 'c') {
            y++;
        } else if (a[j] == 'b') {
            res = (res + num[j] * y) % mod;
        }
    }
    return res;
}

int dfs(string a, vector<int> pos, int lo, int m) {
    if (m <= lo) {
        return count(a);
    }

    int res = 0;
    for (int j = 0; j < 3; j++) {
        a[pos[lo]] = car[j];
        res = (res + dfs(a, pos, lo + 1, m)) % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (a[i] == '?')
            pos.push_back(i);
    }
    int m = pos.size();
    cout << dfs(a, pos, 0, m) << endl;
}

int main() {
    solve();
}