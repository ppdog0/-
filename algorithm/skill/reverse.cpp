// N头牛排成一列，每头牛向前或向后
// 为了让每头牛向前，一次操作可以使K头连续的牛转向
// 求最少的操作次数M和对应最小的K

// 记录前K头牛的翻转情况和第i头牛的朝向

#include<iostream>

using namespace std;

// 输入
int N;
int dir[MAX_N]; // (0:F, 1:B)

int change[MAX_N];

int solve(int K) {
    int res = 0;
    int sum = 0;
    for (int i = 0; i + K <= N; i++) {
        if ((dir[i] + sum) % 2 != 0) {
            change[i] = 1;
            res++;
        }
        sum += change[i];
        if(0 <= i-K+1)
            sum -= change[i - K + 1];
    }
    for (int i = N - K + 1; i < N; i++) {
        if((dir[i] + sum) % 2 != 0)
            return -1;
        if(0 <= i-K+1)
            sum -= change[i - K + 1];
    }
    return res;
}

int main() {
    cin >> N;
    int res = -1;
    int K = 1, k = 1;

    while (true) {
        int num = solve(k);
        if ((0 <= num && num < res))
        {
            res = num;
            K = k;
        }
        if(num < 0)
            break;
        k++;
    }
    cout << res << " " << K << endl;
}


// 有一个MxN的格子，每个格子可以翻转正反面，一面是黑色，另一面是白色
// 每次翻转一个格子，与它上下左右相邻接的格子也会被翻转
// 求最小翻转次数

// 确定第一排的翻转方式，从左至右，从上至下依次向后递推

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_M = 16;
const int MAX_N = 16;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

//输入
int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N]; //最优解
int flip[MAX_M][MAX_N]; //中间结果

//查询(x,y)的颜色
int get(int x, int y) {
    int c = tile[x][y];
    for (int d = 0; d < 5; d++)
    {
        int x2 = x + dx[d], y2 = y + dy[d];
        if(0<=x2&&x2<M&&0<=y2&&y2<N)
            c += flip[x2][y2];
    }
    return c % 2;
}

//求出第1行确定情况下的最小操作次数
//不存在解的话返回-1
int calc() {
    //求出从第2行开始的翻转方法
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            if(get(i-1,j)!=0)
                flip[i][j] = 1;
    }

    //判断最后一行是否全白
    for (int j = 0; j < N; j++)
    {
        if(get(M-1,j)!=0)
            return -1;
    }

    //统计翻转次数
    int res = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            res += flip[i][j];

    return res;
}

void solve() {
    int res = -1;

    //按照字典序尝试第一行的所有可能性
    for (int i = 0; i < 1 << N; i++) //10000(N个0),二进制枚举
    {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < N; j++)
        {
            flip[0][N - j - 1] = i >> j & 1; //i >> j 第j位
        }
        int num = calc();
        if(num>=0&&(res<0||res>num))
        {
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if(res<0)
        printf("IMPOSSIBLE\n");
    else
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
    }
}

int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &tile[i][j]);
    solve();
    return 0;
}

// 世界名画陈列馆

// #include<iostream>
// #include<cstring>

// using namespace std;
// const int MAX_M = 16;
// const int MAX_N = 16;
// const int dx[5] = {-1, 0, 0, 0, 1};
// const int dy[5] = {0, -1, 0, 1, 0};

// // 输入
// int M, N;
// int tile[MAX_M][MAX_N];

// int flip[MAX_M][MAX_N];
// int opt[MAX_M][MAX_N];

// bool get(int x, int y) {
//     if(tile[x][y] == 0)
//         return true;
//     int sum = 0;
//     for (int i = 0; i < 5; i++) {
//         int tx = x + dx[i], ty = y + dy[i];
//         if(0 <= tx && tx < M && 0 <= ty && ty < N)
//             sum += flip[tx][ty];
//     }
//     return sum != 0;
// }

// int calc() {
//     for (int i = 1; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             if(!get(i-1, j))
//                 flip[i][j] = 1;
//         }
//     }

//     for (int i = 0; i < N; i++)
//         if(!get(M-1, i))
//             flip[M - 1][i] = 1;

//     int res = 0;
//     for (int i = 1; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             res += flip[i][j];
//         }
//     }
//     return res;
// }

// void solve() {
//     int res = -1;
//     for (int i = 0; i < 1 << N; i++) {
//         memset(flip, 0, sizeof(flip));
//         for (int j = 0; j < N; j++) {
//             flip[0][j] = i >> j & 1;
//         }
//         int num = calc();

//         if((0 <= num) && ( res < 0 || num < res) ) {
//             res = num;
//             memcpy(opt, flip, sizeof(flip));
//         }
//     }
    
//     for (int i = 0; i < M; i++)
//         for (int j = 0; j < N; j++)
//             printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
// }

// int main() {
//     scanf("%d%d", &M, &N);
//     for (int i = 0; i < M; i++)
//         for (int j = 0; j < N; j++)
//             cin >> tile[i][j];
//     solve();
//     return 0;
// }
