#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int ans = 0;
    for (int l = 0; l < N; l++) {
        int x = a[l];
        for (int r = l; r < N; r++) {
            x = min(x, a[r]);
            ans = max(ans, x * (r - l + 1));
        }
    }
    cout << ans << endl;
}