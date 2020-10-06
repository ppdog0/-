#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<vector<int>> edge(N + 1, vector<int>(N + 1, 0));
    int m, n;
    while(M--) {
        cin >> m >> n;
        edge[m][n] = edge[n][m] = 1;
    }

    int ans = 0;
    vector<int> vertex(N);
    for (int i = 1; i <= N; i++)
        vertex[i - 1] = i;
    do{
        bool flag = true;
        for (int i = 1; i < N; i++) {
            if(!edge[vertex[i-1]][vertex[i]])
                flag = false;
        }
        if (flag)
            ans++;
    } while (next_permutation(vertex.begin() + 1, vertex.end()));

    cout << ans << endl;
    return 0;
}