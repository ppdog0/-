#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N;

int main()
{
    cin >> N;
    vector<long long> rec(N);
    long long a, b;
    long long t = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        rec[i] = a + a + b;
        t -= a;
    }
    sort(rec.begin(), rec.end());
    long long ans = 0;
    while(t <= 0) {
        t += rec.back();
        rec.pop_back();
        ans++;
    }
    cout << ans << endl;
}
