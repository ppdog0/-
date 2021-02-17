// A1046

#include<iostream>
#include<algorithm>

using namespace std;

void solve() {
    int n, q;
    cin >> n;
    int sum = 0, dis[n + 1], x;
    dis[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        dis[i] = sum;
    }
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        if (r < l)
            swap(l, r);
        int temp = dis[r - 1] - dis[l - 1];
        cout << min(temp, sum - temp);
    }
}

int main()
{
    solve();
}