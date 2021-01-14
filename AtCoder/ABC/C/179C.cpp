#include<iostream>

using namespace std;

long long N;

long long bi_search(long long sum) {
    long long lo = 1, hi = N + 1;
    long long mid;
    while(1 < hi - lo) {
        mid = (lo + hi) >> 1;
        if(mid <= sum)
            lo = mid;
        else if (sum < mid)
            hi = mid;
    }
    return lo;
}

int main() {
    cin >> N;
    N--;
    long long sum = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++)
        ans += (N / i);
    // for (int i = 1; i <= N; i++)
    //     for (int j = 1; j <= N / i; j++) {
    //         sum = i * j;
    //         if( bi_search(sum) == sum)
    //             ans++;
    //     }
    cout << ans << endl;
}