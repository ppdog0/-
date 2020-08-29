#include<cstdio>
#include<vector>
using namespace std;
// 用二维vector来表示矩阵
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 10007;

// | 2 1 0 | | 1 |
// | 2 2 2 | | 0 |
// | 0 1 2 | | 0 |

// 计算A*B
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }
    return C;
}

// 计算A^n
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size();i++) {
        B[i][i] = 1;
    }
    while(n > 0) {
        if(n & 1)
            B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

// 输入
int N;

void solve() {
    mat A(3, vec(3));
    A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
    A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
    A = pow(A, N);
    printf("%d\n", A[0][0]);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        solve();
    }
    return 0;
}