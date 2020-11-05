// //递归实现回溯
// //回溯就是递归的结束，返回上一层需要进行数据的返回类似于中断的断点保护
// //子集树
// //回溯法只要就是要有约束函数和限界函数（左，右）；
// //限界函数：当前所有的价值+剩余的所有价值之和小于bestv，则减去右子树；

// #include<iostream>

// using namespace std;
// const int max_n = 100;

// // 输入
// int N, W;
// int v[max_n], w[max_n];

// int cw = 0, cv = 0; // 当前物品重量、价值
// int bestv = 0;
// bool used[max_n]; // 是否使用
// bool flag = false;

// int remain(int i) {
//     int z = 0;
//     for (int j = i + 1; j < N; j++)
//         z += v[j];
//     return z;
// }

// void back(int i) {
//     if (N <= i) { // 递归基
//         if(bestv < cv)
//             bestv = cv;
//         flag = true;
//         return;
//     }
//     if (cw + w[i] <= W) {
//         used[i] = true;
//         cw += w[i];
//         cv += v[i];
//         back(i + 1);
//         cw -= w[i];
//         cv -= v[i];
//     }
//     if (flag) { // 剪枝
//         int z = remain(i);
//         if (z + cv < bestv) {
//             return;
//         }
//     }
//     used[i] = false;
//     back(i + 1);
// }

// int main() {
//     cin >> N >> W;
//     for (int i = 0; i < N; i++)
//         cin >> v[i] >> w[i];
//     back(0);
//     cout << bestv << endl;
// }

/****************************************************************/

// #include<iostream>

// using namespace std;

// const int max_e = 50;

// // 输入
// int n, k, m; // 点 边 颜色数

// int color[max_e];
// int sum = 0;
// bool graph[max_e][max_e] = {false};

// bool pd(int x, int y) { // 判断x能不能涂y
//     for (int i = 0; i < n; i++) {
//         if (graph[x][i] && color[i]==y)
//             return false;
//     }
//     return true;
// }

// void search(int x) {
//     if(n <= x) {
//         for (int i = 0; i < n; i++) {
//             if(color[i]==0)
//                 return;
//         }
//         sum++;
//         return;
//     }
//     for (int y = 1; y <= m; y++) {
//         if(pd(x,y)) {
//             color[x] = y; // x涂第i个颜色
//             search(x + 1);
//             color[x] = 0; // 回溯
//         }
//     }
// }

// int main() {
//     cin >> n >> k >> m;
//     int x, y;
//     for (int i = 0; i < k; i++) {
//         cin >> x >> y;
//         graph[x-1][y-1] = graph[y-1][x-1] = true;
//     }
//     search(0);
//     cout << sum << endl;
// }

/****************************************************************/

// #include<iostream>
// #include<stack>
// #include<utility>

// using namespace std;

// // const char maze[10][10] = {'B', 'B', 'B', 'B'}
// const int maze[9][9] = {
//     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 1, 0, 0, 0, 1, 0},
//     {0, 0, 0, 1, 0, 0, 0, 1, 0},
//     {0, 0, 0, 0, 0, 1, 1, 0, 0},
//     {0, 0, 1, 1, 1, 0, 0, 0, 0},
//     {0, 0, 0, 0, 1, 0, 0, 0, 0},
//     {0, 0, 1, 0, 0, 0, 1, 0, 0},
//     {0, 0, 1, 1, 1, 0, 1, 1, 0},
//     {0, 1, 0, 0, 0, 0, 0, 0, 0},
// };
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// bool used[9][9] = {false};
// stack<pair<int, int>> record;

// bool dfs(int x, int y) {
//     record.push(pair<int, int>(x, y));
//     if(x==8 && y==8) {
//         // 打印路径
//         while(record.size()) {
//             pair<int, int> res = record.top();
//             record.pop();
//             cout << "(" << res.first << ", " << res.second << ")"
//                  << " ";
//         }
//         cout << endl;
//         return true;
//     }
//     used[x][y] = true;
//     for (int i = 0; i < 4; i++) {
//         int cx = x + dx[i], cy = y + dy[i];
//         if (1<=cx && cx<=8 && 1<=cy && cy<=8 && maze[cx][cy] == 0 && !used[cx][cy]) {
//             if(dfs(cx, cy)) return true;
//         }
//     }
//     used[x][y] = false;
//     record.pop();
//     return false;
// }

// int main() {
//     dfs(1, 1);
// }
