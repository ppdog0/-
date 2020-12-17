#include<iostream>
#include<cstring>

using namespace std;

const int max_n = 100;

int n;
int nums[max_n];

void merge(int lo, int mi, int hi) {
    int *a = nums + lo;
    int lb = mi - lo, lc = hi - mi;
    int *c = nums + mi;
    int *b = new int[lb];
    memcpy(b, a, sizeof(int) * lb);
    int k = 0, k1 = 0, k2 = 0;
    while(k1 < lb && k2 < lc) {
        if(c[k2] < b[k1])
            a[k++] = c[k2++];
        else
            a[k++] = b[k1++];
    }
    if (k1 < lb)
        a[k++] = b[k1++];
    if (k2 < lc)
        a[k++] = c[k2++];
}
void mergeSort(int lo, int hi) {
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) / 2;
    mergeSort(lo, mi); mergeSort(mi, hi);
    merge(lo, mi, hi);
}

int partition(int lo, int hi) {
    swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
    int pivot = nums[lo];
    while(lo < hi) {
        while(lo < hi && pivot <= nums[hi])
            hi--;
        nums[lo] = nums[hi];
        while(lo < hi && nums[lo] <= pivot)
            lo++;
        nums[hi] = nums[lo];
    }
    nums[lo] = pivot;
    return lo;
}
void quickSort(int lo, int hi) {
    if (hi - lo < 2)
        return;
    int mi = partition(lo, hi - 1);
    quickSort(lo, mi); quickSort(mi + 1, hi);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    // mergeSort(0, n);
    quickSort(0, n);
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}