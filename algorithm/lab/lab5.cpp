// 使用动态规划
// dp[w]:总重量不超过w的物品，价值的最大值
// dp[w+w[i]]==max(dp[w+w[i]], dp[w]+v[i]);
// 复杂度o(nsum(W/w[i]))=o(nW)

// #include<iostream>
// #include<cstring>
// #include<algorithm>

// using namespace std;
// const int max_n = 100;

// int n, W;
// int w[max_n], v[max_n];
// int dp[max_n];

// int main() {
//     memset(dp, 0, sizeof(dp));
//     cin >> n >> W;
//     for (int i = 0; i < n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 0; i < n; i++) {
//         for (int j = W; w[i] <= j; j--) {
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//         }
//     }
//     cout << dp[W] << endl;
// }

// ****************************************************
// 带权区间调度

// #include<iostream>
// #include<algorithm>
// #include<cstring>

// using namespace std;
// const int max_n = 100;

// struct node {
//     int start, end;
//     int value;
// };

// int n;
// node num[max_n];

// int dp[max_n];
// int p[max_n];

// bool comp(const node& node1, const node& node2) {
//     return node1.end <= node2.end;
// }

// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> num[i].start >> num[i].end >> num[i].value;
//     sort(num + 1, num + n + 1, comp);

//     memset(p, 0, sizeof(p));
//     for (int i = 2; i <= n; i++) {
//         for (int j = i - 1; 0 < j; j--) {
//             if (num[j].end <= num[i].start) {
//                 p[i] = j;
//                 break;
//             }
//         }
//     }

//     memset(dp, 0, sizeof(dp));
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         dp[i] = max(dp[i - 1], dp[p[i]] + num[i].value);
//     }
//     cout << dp[n] << endl;
// }

// ****************************************************
// 汽车行驶问题
// #include <iostream>
// #define INF 100000;

// using namespace std;
// const int max_n = 100;

// int N, K, A, B, C;
// int a[max_n + 1][max_n + 1]; // N*N网格
// int f[max_n + 1][max_n + 1][3]; // dp
// int s[4][3] = {{-1, 0, B}, {0, -1, B}, {1, 0, 0}, {0, 1, 0}}; // 4个方向，第三个参数是价格B

// int main()
// {
//     cin >> N >> K >> A >> B >> C;

//     for(int i=1;i<=N;++i)
// 		for(int j=1;j<=N;++j)
//             cin >> a[i][j];

//     //初始化
//     for(int i=1;i<=N;++i)
// 		for(int j=1;j<=N;++j)
// 			{
//                 f[i][j][0] = INF;
//                 f[i][j][1] = K;
//             }
//     //起点值初始化
//     f[1][1][0] = 0;
//     f[1][1][1] = K;

//     for (int x = 1; x <= N; ++x)
//         for (int y = 1; y <= N; ++y)
//         { 
// 			if(x == 1 && y == 1) continue;
// 			int minmoney=INF; //minmoney存储（x,y）上个位置的最小money
//             int minstep;
// 			int tmpmoney,tmpstep;

//             for (int i = 0; i <= 3; ++i) //遍历上一个位置的所有可能情况
//             {
//                 int dx = x + s[i][0], dy = y + s[i][1];
//                 if(dx<1||dx>N||dy<1||dy>N)
//                     continue; //超边界

//                 tmpmoney = f[dx][dy][0] + s[i][2];
//                 tmpstep = f[dx][dy][1] - 1;
//                 if(a[x][y] == 1) { //遇油站
//                     tmpmoney += A;
//                     tmpstep = K;
//                 }
//                 if(a[x][y] == 0 && tmpstep == 0 && (x != N || y != N)) { //没油了
//                     tmpmoney += A + C;
//                     tmpstep = K;
//                 }      
//                 if(tmpmoney < minmoney)//更新最小值 (最后储存上个位置中费用最少的) 
// 				{
// 					minmoney = tmpmoney;
//                     minstep = tmpstep;
//                 }
// 			} 
							
// 			if(f[x][y][0] > minmoney)//更新f 
// 			{
//                 f[x][y][0] = minmoney;
//                 f[x][y][1] = minstep;
//             } 
// 		}
//     // cout << endl;
//     // for(int i=1;i<=N;++i)
// 	// {	
// 	// 	for(int j=1;j<=N;++j)
// 	// 		cout<<f[i][j][0]<<' ';
// 	// 	cout<<endl; 
// 	// }
//     cout << f[N][N][0] << endl;
//     return 0;
// }

// 公共子序列
// #include<iostream>

// using namespace std;

// const int max_n = 100;
// const int max_m = 100;

// int n, m;
// char s[max_n], t[max_m];
// int dp[max_n][max_m];

// void solve() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (s[i] == t[j]) {
//                 dp[i + 1][j + 1] = dp[i][j] + 1;
//             } else {
//                 dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
//             }
//         }
//     }
//     if(dp[n][m] == m)
//         cout << "Yes" << endl;
//     cout << dp[n][m] << endl;
// }

// int main() {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//         cin >> s[i];
//     for (int i = 0; i < m; i++)
//         cin >> t[i];
//     solve();
// }