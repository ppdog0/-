#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

long long N, M;

int main() {
    cin >> N >> M;
    long long A[M + 2];
    A[0] = 0;
    A[M + 1] = N + 1;
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    sort(A, A + M + 2);

    vector<long long> rec;
    long long k = N;
    for (int i = 1; i < M + 2; i++) {
        long long len = A[i] - A[i-1] - 1;
        if (len != 0) {
            rec.push_back(len);
            k = min(k, len);
        }
    }

    long long ans = 0;
    for (auto len:rec) {
        ans += (len + k - 1) / k;
    }
    cout << ans << endl;
}