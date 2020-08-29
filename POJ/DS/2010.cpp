#include<cstdio>
#include<algorithm>
#include<queue> //priority_queue
using namespace std;
int N, C;
long long F;
struct cow {
    int score;
    int cost;
} cows[100001];
priority_queue<int> pq1, pq2;
int f1[100001], f2[100001];
bool cmp(cow a, cow b) {
    if(a.score == b.score)
        return a.cost < b.cost;
    return a.score < b.score;
}
int main() {
    scanf("%d%d%lld", &N, &C, &F);
    for (int i = 0; i < C; i++) {
        scanf("%d%d", &cows[i].score, &cows[i].cost);
    }
    sort(cows, cows + C, cmp);
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < C; i++) {
        if(i < N/2) {
            pq1.push(a[i].cost);
            sum1 += a[i].cost;
            continue;
        }
        f1[i] = sum1;
        if(pq1.top() <= a[i].cost) {
            continue;
        }
        sum1 -= q1.top();
        q1.pop();
        sum1 += a[i].cost;
        q1.push(a[i].cost);
    }
        ;
    return 0;
}

// int ans = 0;
//     for (int i = C - 1; 0 <= i; i--) {
//         if(ans == N)
//             break;
//         if(cows[i].second < F) {
//             F -= cows[i].second;
//             pq.push(cows[i].second);
//             ans++;
//         } else {
//             int x = pq.top();
//             pq.pop();
//             F += x;
//             ans--;
//         }
//     }