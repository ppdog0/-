#include<iostream>

using namespace std;

int N;
int nums[101];

int main() {
    cin >> N;
    int t = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        t = max(t, nums[i]);
    }
    int m = 0, ans = 0;
    for (int i = 2; i <= t; i++) {
        int res = 0;
        for (int j = 0; j < N; j++) {
            if(nums[j] % i == 0)
                res++;
        }
        if(ans < res) {
            ans = res;
            m = i;
        }
    }
    cout << m << endl;
}