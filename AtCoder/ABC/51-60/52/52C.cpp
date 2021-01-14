/*
 * Created Date: Sunday, September 27th 2020, 2:25:40 pm
 * Author: ppdog
 */

// 对于x，素数分解 x = (p * n) * (q * m), p, q为素数, 则x的约数个数为 (n + 1) * (m + 1)
// 所以有 N! = 1 * 2 * ... (N - 1) * (N), 找到1到N的所有素数(除1外), 
// 由于N很小，可以用两个循环，复杂度为0 + 1 + 2 + ... + N-1 = o(N^2)
// 如果N很大，可以考虑用位图(bitmap)统计1到N的所有质数，空间消耗为N/8个字节，时间复杂度为o(nlogn)


#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;
int N;
char *M;

void init(int n = 8) {
    M = new char[(n + 7) / 8];
    memset(M, 0, (n + 7) / 8);
}

void set(int n) {
    M[n >> 3] |= (0x80 >> (n & 0x07));
}

bool test(int n) {
    return M[n >> 3] & (0x80 >> (n & 0x07));
}

void prime_set(int n) {
    set(0); set(1);
    for (int i = 2; i < n; i++)
        if( !test(i) )
            for (int j = i * i; j <= n; j += i)
                set(j);
}

int main() {
    cin >> N;
    long long ans = 1;
    init(N);
    prime_set(N);
    for (int i = 2; i <= N; i++) {
        if(!test(i)) { // 1到N的所有质数
            long long res = 0;
            for (int temp = i; temp <= N; temp *= i)
                res += N / temp;
            ans *= (res + 1) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}