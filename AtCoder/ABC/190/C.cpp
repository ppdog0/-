#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> cond(M);
    for (auto &[A, B] : cond)
        cin >> A >> B;
    int K;
    cin >> K;
    vector<pair<int, int>> choice(K);
    for (auto &[C, D] : choice)
        cin >> C >> D;

    int ans = 0;
    for (int bit = 0; bit < 1 << K; bit++)
    {
        vector<bool> ball(N);
        for (int i = 0; i < K; i++)
        {
            const auto [C, D] = choice[i];
            ball[bit & 1 << i ? C : D] = 1;
        }
        int cnt = 0;
        for (auto [A, B] : cond)
            if (ball[A] && ball[B])
                cnt++;
        if (ans < cnt)
            ans = cnt;
    }
    cout << ans << endl;
}

// #include<iostream>

// using namespace std;

// int n, m, k;

// int main() {
//     cin >> n >> m;
//     int a[m], b[m];
//     cin >> k;
//     int p[k];
// }