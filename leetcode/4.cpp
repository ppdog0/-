#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    int result[m + n];
    int k1 = 0, k2 = 0;
    int k = 0;
    while (k1 < m && k2 < n)
    {
        if (nums1[k1] < nums2[k2])
            result[k++] = nums1[k1++];
        else
            result[k++] = nums2[k2++];
    }
    while (k1 < m)
        result[k++] = nums1[k1++];
    while (k2 < n)
        result[k++] = nums2[k2++];

    return (double)(result[(k-1) / 2] + result[(k) / 2]) / 2;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    cout << findMedianSortedArrays(nums1, nums2);
}