#include<iostream>

using namespace std;

long long N;

int count(long long N) {
    int digits = 0;
    while(N) {
        digits++;
        N /= 10;
    }
    return digits;
}

int main() {
    cin >> N;
    int ans = count(N);

    for (long long i = 1LL; i * i <= N; i++) {
        if(N%i != 0)
            continue;
        int res = max(count(i), count(N / i));
        ans = min(ans, res);
    }
    cout << ans << endl;
}