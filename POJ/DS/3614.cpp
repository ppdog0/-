#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> P;
int C, L;
P cows[2501], bottles[2501];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    scanf("%d%d", &C, &L);
    for (int i = 0; i < C; i++)
        scanf("%d%d", &cows[i].first, &cows[i].second);
    for (int i = 0; i < L; i++)
        scanf("%d%d", &bottles[i].first, &bottles[i].second);
    sort(cows, cows + C);
    sort(bottles, bottles + L);
    int j = 0, ans = 0;
    for (int i = 0; i < L; i++) {
        while (j < C && cows[j].first <= bottles[i].first) {
            pq.push(cows[j].second);
            j++;
        }
        while (!pq.empty() && bottles[i].second) {
            int max = pq.top();
            pq.pop();
            if (max < bottles[i].first)
                continue;
            bottles[i].second--;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}