// #include<iostream>
// #include<queue>
// #include<algorithm>

// using namespace std;
// const int max_n = 100;

// int n, W;
// int cw = 0, cv = 0, bestv = 0;

// struct obj {
//     int w;
//     int v;
// };

// bool cmp(obj &obj1, obj &obj2) {
//     return (obj2.v / obj2.w) < (obj1.v / obj1.w);
// }

// obj t[max_n];

// struct node {
//     int cw;
//     int cv;
//     int up;
//     int k;
//     bool operator<(const node& a) const {
//         return up < a.up;
//     }
// };

// priority_queue<node> q;

// int bound(int i) {
//     int left = W - cw, b = cv;
//     while(i < n && t[i].w < left) {
//         left -= t[i].w;
//         b += t[i].v;
//         i++;
//     }
//     if(i < n)
//         b += left * t[i].v / t[i].w;
//     return b;
// }

// void solve() {
//     int k = 0;
//     node c;
//     c.cw = cw;
//     c.cv = cv;
//     c.k = k;
//     q.push(c);
//     while (!q.empty()) {
//         node p = q.top(); q.pop();
//         cw = p.cw;
//         cv = p.cv;
//         k = p.k;

//         if(cw + t[k].w <= W) {
//             if(bestv < cv+t[k].v)
//                 bestv = cv + t[k].v;

//             node a;
//             a.cw = cw + t[k].w;
//             a.cv = cv + t[k].v;
//             a.up = bound(k);
//             a.k = k + 1;
//             if(k+1 < n)
//                 q.push(a);
//         }
//         int up = bound(k + 1);
//         if(bestv < up) {
//             node m;
//             m.cw = cw;
//             m.cv = cv;
//             m.up = up;
//             m.k = k + 1;
//             if(k+1 < n)
//                 q.push(m);
//         }
//     }

//     cout << bestv << endl;
// }

// int main() {
//     cin >> n >> W;
//     for (int i = 0; i < n; i++) {
//         cin >> t[i].w >> t[i].v;
//     }
//     sort(t, t + n, cmp);
//     solve();
// }



// *************************************************
// TSP问题

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
const int max_n = 10;
const int INF = 100;

using namespace std;

// 输入
int n;
int graph[4][4] = {
    {-1, 30, 6,  4},
    {30, -1, 5,  10},
    {6,  5,  -1, 20},
    {4,  10, 20, -1}
};

int lo; // 下界
int bestp; // 最短路径长度

struct edge {
    int u; // 起点
    int v; // 终点
    int l; // 长度
};
edge path[max_n][2]; // 最短的两条路
vector<edge> visitedE; // 已访问的边
bool visitedN[max_n]; // 已访问的点

struct node
{
    int k; // 末尾的点
    int lo; // 下界
    bool visitedN[max_n]; // 已访问的点
    vector<edge> visitedE; // 已访问的边
    edge path[max_n][2]; // 最短的两条路
    bool operator<(const node& a) {
        return lo <  a.lo;
    }
};
priority_queue<node> q; // 优先级队列

int bound() {
    int res = 0;
    edge e = visitedE.back();
    res += e.l - path[e.u][1].l;
    path[e.u][1] = e;
    swap(path[e.u][0], path[e.u][1]);

    res += e.l - path[e.v][1].l;
    path[e.v][1] = e;
    swap(path[e.v][0], path[e.v][1]);

    return (lo * 2 + res) / 2;
}

void solve() {
    int k = 0; // 起点
    node it;
    it.k = k;
    it.lo = lo;
    it.visitedE = visitedE;
    memcpy(it.visitedN, visitedN, sizeof(visitedN));
    memcpy(it.path, path, sizeof(path));
    it.visitedN[k] = true;
    q.push(it);
    while(!q.empty()) {
        node p = q.top();
        q.pop();
        k = p.k;
        lo = p.lo;
        visitedE = p.visitedE;
        memcpy(path, p.path, sizeof(p.path));
        memcpy(visitedN, p.visitedN, sizeof(p.visitedN));
        if (p.lo < bestp) {
            bool flag = false;
            for (int i = 1; i < n; i++) {
                if (i != k && !visitedN[i]) {
                    flag = true;
                    node m = p;
                    edge e;
                    e.u = k;
                    e.v = i;
                    e.l = graph[k][i];
                    m.visitedE.push_back(e);
                    m.visitedN[i] = true;
                    m.k = i;
                    m.lo = bound();
                    q.push(m);
                }
            }
            if (!flag && p.lo < bestp)
                bestp = ((p.lo * 2) + graph[k][0] - path[k][1].l) / 2;
        }
    }
}

int main() {
    //初始化
    lo = 0;
    n = 4;
    bestp = INF;
    visitedN[max_n] = {false};
    memset(path, 0, sizeof(path));
    for (int i = 0; i < n; i++) { // 找到每个点最小的两条边(入边和出边)
        edge min1, min2;
        min1.l = graph[i][0];
        min2.l = graph[i][1];
        if (min2.l < min1.l)
            swap(min1, min2);
        for (int j = 2; j < n; j++) {
            if(graph[i][j] < min1.l) {
                min1.l = graph[i][j];
                min1.u = i;
                min1.v = j;
            }
            else if (graph[i][j] < min2.l) {
                min2.l = graph[i][j];
                min2.u = i;
                min2.v = j;
            }
        }
        path[i][0] = min1;
        path[i][1] = min2;
        lo += min1.l + min2.l;
    }
    lo = lo / 2;
    solve();
}
