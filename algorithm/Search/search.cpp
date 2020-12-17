#include<iostream>

using namespace std;
const int max_n = 100;

int n;
int nums[max_n];

int binSearch(int lo, int hi, int num) {
    int mid;
    while(1 < hi - lo) {
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

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int num;
    cin >> num;
    cout << binSearch(0, n, num);
}