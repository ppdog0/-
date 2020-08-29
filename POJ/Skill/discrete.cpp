#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
const int MAX_N = 10;
//输入
int W=10, H=10, N=10;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

//填充用
bool fld[MAX_N * 6][MAX_N * 6];

//对x1和x2进行坐标离散化，并返回离散化之后的宽度
int compress(int *x1, int *x2, int w) {
    vector<int> xs;

    for (int i = 0; i < N; i++)
        for (int d = -1; d <= 1; d++)
        {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if(1<=tx1&&tx1<=W)
                xs.push_back(tx1);
            if(1<=tx2&&tx2<=W)
                xs.push_back(tx2);
        }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < N; i++)
    {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

void solve() {
    //坐标离散化
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    //填充有直线的部分
    memset(fld, 0, sizeof(fld));
    for (int i = 0; i < N; i++)
        for (int y = Y1[i]; y <= Y2[i]; y++)
            for (int x = X1[i]; x <= X2[i]; x++)
            {
                fld[y][x] = true;
            }
    
    //求区域的个数
    int ans = 0;
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if(fld[y][x])
                continue;
            ans++;

            //宽度优先搜索
            queue<pair<int, int>> que;
            que.push(make_pair(x, y));
            while(!que.empty())
            {
                int sx = que.front().first, sy = que.front().second;
                que.pop();

                for (int i = 0; i < 4; i++)
                {
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if (tx < 0 || W <= tx || ty < 0 || H <= ty)
                        continue;
                    if(fld[ty][tx])
                        continue;
                    que.push(make_pair(tx, tx));
                    fld[ty][tx] = true;
                }
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    int X1[5] = {1, 1, 4, 9, 10};
    int X2[5] = {6, 10, 4, 9, 10};
    compress(X1, X2, 5);
    for (int i = 0; i < 5; i++)
        printf("%d and %d            ", X1[i], X2[i]);
    return 0;
}