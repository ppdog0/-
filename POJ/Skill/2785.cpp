#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 4e3 + 10;
//输入
int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int CD[MAX_N * MAX_N]; //C和D中数字的组合方法

void solve() {
    // 枚举从C和D中取出数字的所有方法
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            CD[i * n + j] = C[i] + D[j];

    sort(CD, CD + n * n);

    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int cd = -(A[i] + B[j]);
            // 取出C和D中和为cd的部分
            res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
        }

    printf("%lld\n", res);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    }
    solve();
    return 0;
}