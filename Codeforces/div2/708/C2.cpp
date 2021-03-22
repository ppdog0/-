#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void cal(int n, int nums[]) {
    if (n % 2 == 1) nums[0] = 1, nums[1] = n / 2, nums[2] = n / 2;
    else if (n % 4 == 0) nums[0] = n / 2, nums[1] = n / 4, nums[2] = n / 4;
    else nums[0] = 2, nums[1] = n / 2 - 1, nums[2] = n / 2 - 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int nums[3];
    cal(n - (k - 3), nums);
    for (int i = 0; i < 3; i++) {
        cout << nums[i] << " ";
    }
    for (int i = 0; i < k - 3; i++) {
        cout << 1 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}