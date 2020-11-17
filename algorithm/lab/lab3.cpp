// #include<iostream>
// #include<vector>
// #include<queue>
// #include<algorithm>
// #include<utility>

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

using namespace std;

int main() {}
