#include<iostream>
#include<algorithm>

using namespace std;

int N;

int main()
{
    cin >> N;
    long long A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    long long ans = 0, x = 0;
    for (int i = 0; i < N - 1; i++) {
        x += A[N - 1 - i];
        ans -= A[i] * (N - i - 1);
        ans += x;
    }
    cout << ans << endl;
}
