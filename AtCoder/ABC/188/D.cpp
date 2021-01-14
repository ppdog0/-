#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long N, C;
vector<pair<long, long>> rec;

int main() {
    cin >> N >> C;
    long long a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        rec.push_back(make_pair(a, c));
        rec.push_back(make_pair(b + 1, -c));
    }
    sort(rec.begin(), rec.end());
    long long cur = 0, t = 0;
    long long ans = 0;
    for (auto [time, cost] : rec) {
        if (t != time) {
            ans += min(cur, C) * (time - t);
            t = time;
        }
        cur += cost;
    }
    cout << ans << endl;
}