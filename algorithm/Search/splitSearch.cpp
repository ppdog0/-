#include <iostream>

using namespace std;
const int max_n = 100;

int n;
int nums[max_n];

int binSearch(int lo, int hi, int num)
{
    int mid;
    while (1 < hi - lo)
    {
        mid = (lo + hi) >> 1;
        if (nums[mid] == num)
            return mid;
        else if (nums[mid] < num)
            lo = mid;
        else
            hi = mid;
    }
    return nums[lo] == num ? lo : -1;
}

int splitSearch(int lo, int hi) {
    int mid;
    while (1 < hi - lo) {
        mid = (lo + hi) >> 1;
        if (0 < mid-1 && nums[mid] < nums[mid-1])
            return mid;
        if (mid+1 < n && nums[mid+1] < nums[mid])
            return mid + 1;

        if (nums[mid] < nums[lo])
            hi = mid;
        else
            lo = mid;
    }
    return n;
}

int search(int lo, int hi, int num) {
    int k = splitSearch(lo, hi);
    int res = binSearch(0, k, num);
    if (res != -1)
        return res;
    if (k < n)
        return binSearch(k, n, num);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int num;
    cin >> num;
    cout << search(0, n, num);
}