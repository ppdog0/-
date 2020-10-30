// 01背包问题
// 对于n个物品，重量和价值分别为wi,vi
// 从中选取物品，总重量不超过W，求价值的最大值

// 使用蛮力法，二进制枚举

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;
// const int max_n = 100;

// int n, W;
// int w[max_n], v[max_n];

// int main() {
//     cin >> n >> W;
//     for (int i = 0; i < n; i++) {
//         cin >> w[i] >> v[i];
//     }
//     int ans = 0;
//     for (int i = 1; i < 1 << n; i++) {
//         int wp = 0, vp = 0;
//         for (int j = 0; j < n; j++) {
//             if(i & (1<<j)) {
//                 wp += w[j];
//                 vp += v[j];
//             }
//         }
//         if(wp < W)
//             ans = max(ans, vp);
//     }
//     cout << ans << endl;
// }

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
//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j + w[i] <= W; j++) {
//     //         dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
//     //     }
//     // }
//     cout << dp[W] << endl;
// }

// 旅行商问题

// 暴力枚举，全排列枚举

// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int INF = 10e7;
// int n = 4;
// //存储城市之间的距离
// int g[4][4] = { {INF,3,   6,  7},
//                 {12, INF, 2,  8},
//                 {9,  6,   INF,2},
//                 {3,  7,   6,  INF} };
// int place[4] = {0, 1, 2, 3};

// int main () {
//     // cin >> n;
//     int ans = INF;
//     do {
//         int cost = 0;
//         for (int i = 0; i < n-1; i++)
//             if (g[place[i]][place[i+1]] != INF)
//                 cost += g[place[i]][place[i + 1]];
//         cost += g[place[3]][place[0]];
//         ans = min(ans, cost);
//     } while (next_permutation(place, place + n));
//     cout << ans << endl;
// }

// 动态规划
 
// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int INF = 10e7;
// int n = 4;
// //存储城市之间的距离
// int g[4][4] = { {INF,3,   6,  7},
//                 {12, INF, 2,  8},
//                 {9,  6,   INF,2},
//                 {3,  7,   6,  INF} };
// int dp[1 << 4][4];

// int main() {
//     for (int S = 0; S < 1 << n; S++)
//         fill(dp[S], dp[S] + n, INF);
//     dp[(1 << n) - 1][0] = 0;
//     for (int S = (1 << n) - 2; 0 <= S; S--)
//         for (int v = 0; v < n; v++)
//             for (int u = 0; u < n; u++) {
//                 if( !(S >> u & 1) ) {
//                     dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + g[v][u]);
//                 }
//             }
//     cout << dp[0][0] << endl;
// }


// 稳定婚姻匹配

// #include<iostream>
// using namespace std;

// const int N=4;

// void GaleShapley(const int (&man)[N][N],const int (&woman)[N][N],int (&match)[N]){
//     int wm[N][N];    // wm[i][j]: rank from girl i to boy j
//     int choose[N];    // choose[i]: current boyfriend of girl i
//     int manIndex[N]; //    manIndex[i]: how many girls that have rejected boy i
//     int i,j;
//     int w,m;
//     for(i=0;i<N;i++){
//         match[i]=-1;
//         choose[i]=-1;
//         manIndex[i]=0;
//         for(j=0;j<N;j++)
//             wm[i][woman[i][j]]=j;
//     }

//     bool bSingle=false;
//     while(!bSingle){
//         bSingle=true;
//         for(i=0;i<N;i++){
//             if(match[i]!=-1) // boy i already have a girlfriend
//                 continue;
//             bSingle=false;
//             j=manIndex[i]++; // the jth girl that boy i like most
//             w=man[i][j];    
//             m=choose[w];    // current girl w's boyfriend
//             if(m==-1 || wm[w][i]<wm[w][m]){ // if girl w prefer boy i
//                 match[i]=w;
//                 choose[w]=i;
//                 if(m!=-1)
//                     match[m]=-1;
//             }
//         }
//     }
// }

// void Print(const int (&match)[N],int N){
//     for(int i=0;i<N;i++)
//         cout<<"Boy "<<i<<" matches "<<"Girl "<<match[i]<<endl;
//     cout<<endl;
// }

// int main(){
//     int man[N][N]={
//         {2,3,1,0},
//         {2,1,3,0},
//         {0,2,3,1},
//         {1,3,2,0},
//     };
//     int woman[N][N]={
//         {0,3,2,1},
//         {0,1,2,3},
//         {0,2,3,1},
//         {1,0,3,2},
//     };

//     int match[N];
//     GaleShapley(man,woman,match);
//     Print(match,N);

//     return 0;
// }