#include<iostream>
#include<cmath>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    int ans = pow(K - 1, N - 1);
    cout << ans*K << endl;
    return 0;
}