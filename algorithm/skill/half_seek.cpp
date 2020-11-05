// 给定各有n个整数的四个数列A B C D
// 从每个数列中各取出1个数，使四个数的和为0
// 求出这样的组合个数

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

// 给定N，找出是否存在a,b满足
// 3^a + 5^b = N

#include<iostream>
#include<map>

using namespace std;

long long N;
map<int, int> record;

int main() {
    cin >> N;
    int a = 3, sum = 1;
    for (int i = 0; i <= 38; i++) {
        if(a>N)
            break;
        record[a] = sum;
        a *= 3;
        sum++;
    }
    int b = 5, tot = 1;
    for (int i = 0; i <= 26; i++) {
        if(b>N)
            break;
        if(record.count(N-b) == true) {
            cout << record[N - b] << " " << tot << endl;
            return 0;
        }
        b *= 5;
        tot++;
    }
    cout << "-1" << endl;
}