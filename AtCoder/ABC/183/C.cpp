#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
int path[9][9];

int main() {
    cin >> N >> K;
    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i;
        for (int j = 0; j < N; j++) {
            cin >> path[i][j];
        }
    }
    int ans = 0;
    do {
        int res = path[0][order[1]];
        for (int i = 1; i < N - 1; i++)
            res += path[order[i]][order[i + 1]];
        res += path[order[N - 1]][0];
        if(res==K)
            ans++;
    } while (next_permutation(order.begin() + 1, order.end()));
    cout << ans << endl;
}