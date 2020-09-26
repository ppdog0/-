#include<iostream>

using namespace std;
const int MOD = 1e9 + 7;

int N;
int order[100005];

long long pow(long long x, int n) {
    long long res = 1;
    while (0 < n) {
        if(n % 2 != 0)
            res = res * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    cin >> N;
    int num;
    int d = (N - 1) % 2;
    for (int i = 0; i < N; i++){
        cin >> num;
        order[num]++;

        if(num % 2 != d || order[num] > 2 || order[0] > 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << pow(2, N / 2) << endl;
    return 0;
}