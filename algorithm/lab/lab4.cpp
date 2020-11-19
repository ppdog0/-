// // 无序数组输出第k个大小的数
// // 使用快速排序

// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int max_n = 100;

// // 输入
// int n, k;
// int nums[max_n];

// int partition(int lo, int hi) {
//     swap(nums[lo], nums[rand() % (hi - lo + 1)]);
//     int pivot = nums[lo];
//     while(lo < hi) {
//         while((lo < hi) && (pivot <= nums[hi]))
//             hi--;
//         nums[lo] = nums[hi];
//         while((lo<hi) && (nums[lo] <= pivot))
//             lo++;
//         nums[hi] = nums[lo];
//     }
//     nums[lo] = pivot;
//     return lo;
// }

// int quickSort(int lo, int hi, int k) {
//     if (hi - lo < 1)
//         return nums[lo];
//     int mi = partition(lo, hi);
//     if (mi == k)
//         return nums[mi];
//     else if (mi < k)
//         return quickSort(mi + 1, hi, k);
//     else
//         return quickSort(lo, mi - 1, k);
// }

// int main() {
//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];
//     int ans = quickSort(0, n - 1, k - 1);
//     cout << ans << endl;
// }

// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int max_n = 100;

// // 输入
// int n;
// int nums[max_n], temp[max_n];

// int m;
// int r[max_n];

// int cnt = 0;

// void merge(int lo, int hi, int mid)
// {
//     int i=lo;
//     int j=mid + 1;
//     int k=lo;
//     while(i <= mid && j <= hi)
//     {
//         if(nums[i]>nums[j])
//         {
//             cnt += mid - i + 1;
//             r[m++] = nums[i];
//             r[m++] = nums[j];
//             temp[k++] = nums[j++];
//         }
//         else
//             temp[k++] = nums[i++];
//     }

//     while(i <= mid)
//         temp[k++]=nums[i++];
//     while(j <= hi)
//         temp[k++]=nums[j++];
//     for(i=lo; i<=hi; i++)
//         nums[i]=temp[i];
// }    

// void mergeSort(int lo, int hi) {
//     if (lo<hi) {
//         int mid = (lo + hi) / 2;
//         mergeSort(lo, mid);
//         mergeSort(mid + 1, hi);
//         merge(lo, hi, mid);
//     }
// }

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];
//     mergeSort(0, n - 1);
//     cout << cnt << endl;
//     for (int i = 0; i < m; i++)
//         cout << r[i] << " ";
// }

// #include<iostream>
// #include<algorithm>
// #include<cstdio>
// using namespace std;

// const int MAX_SIZE = 10005;

// bool cmp(int a, int b)
// {
//     if(a < b)
//         return true;
//     else
//         return false;
// }

// int cal(int str[], int n)
// {
//     int sum = 0, i, mid;
//     mid = str[n / 2];
//     for (i = 0; i < n; i++)
//         sum += abs(str[i] - mid);
//     return sum;
// }

// int main()
// {
//     int x[MAX_SIZE], y[MAX_SIZE];
//     int n;
//     while(scanf("%d", &n) != EOF)
//     {
//         for (int i = 0; i < n; i++)
//             scanf("%d%d", x + i, y + i);
//         sort(x, x + n, cmp);
//         sort(y, y + n, cmp);
//         printf("%d\n", cal(x, n) + cal(y, n));
//     }
//     return 0;
// }

#include<iostream>

using namespace std;

const int max_n = 100;

int n;
int nums[max_n];

void solve() {
    int min1 = nums[0];
    int max1 = 0;
    for (int i = 0; i < n; i++) {
        if(nums[i] < min1)
            min1 = nums[i];
        else if (max1 < nums[i] - min1)
            max1 = nums[i];
    }
    cout << max1 << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    solve();
}
