#include <iostream>
#include<algorithm>

using namespace std;

// [l,r)
void dfs(int* a, int* pos, int dep, int m, int l, int r) {
    if(r <= l)
        return;
    pos[m] = dep;
    dfs(a, pos, dep + 1, max_element(a + l, a + m) - a, l, m);
    dfs(a, pos, dep + 1, max_element(a + m + 1, a + r) - a, m + 1, r);
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x:a)
        cin >> x;
    int pos[n];
    dfs(a, pos, 0, max_element(a, a + n) - a, 0, n);
    for(int x:pos)
        cout << x << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}