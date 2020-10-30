#include<iostream>
#include<algorithm>

using namespace std;

int r, n;
int x[1001];

int main() {
    while (true) {
        cin >> r >> n;
        if(r == -1 && n == -1)
            break;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        int i = 0, ans = 0;
        while (i<n) {
            int s = x[i++];
            while(i<n && x[i] <= s+r)
                i++;
            int p = x[i - 1];
            while(i<n && x[i] <= p+r)
                i++;
            ans++;
        }
        cout << ans << endl;
    }
}