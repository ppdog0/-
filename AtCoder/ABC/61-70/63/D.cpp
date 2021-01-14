#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
long long A, B, ab;
vector<long long> h;

bool check(long long T) {
    long long sum = T * B;
    long long res = 0;
    for (int i = N - 1; 0 <= i; i--) {
        if (sum < h[i]) {
            res += ceil((double)(h[i] - sum) / ab);
        }
    }
    if (T < res)
        return false;
    return true;
}

void solve() {
    long long hi = h.back() / B + 1;
    long long lo = 0;
    do {
        long long mid = (hi + lo) >> 1;
        if(check(mid)) {
            hi = mid;
        } else
            lo = mid + 1;
    } while (lo < hi);
    cout << hi << endl;
}

int main() {
    cin >> N >> A >> B;
    ab = A - B;
    long long x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        h.push_back(x);
    }
    sort(h.begin(), h.end());
    solve();
}