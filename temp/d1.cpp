// 数组元素循环右移
#include <iostream>

using namespace std;

// [lo, hi]
void reverse(int* a, int lo, int hi) {
    while(lo < hi)
        swap(a[lo++], a[hi--]);
}

void solve() {
    int n, s;
    cin >> n >> s;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    s %= n;
    reverse(nums, 0, n - s - 1);
    reverse(nums, n - s, n - 1);
    reverse(nums, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}

int main()
{
    solve();
}