#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
const long long N = 1'000'000'000'000L;

vector<long long> rec;

void init() {
    for (long long i = 1; i*i*i <= N; i++) {
        rec.push_back(i * i * i);
    }
}

void solve() {
    long long x;
    cin >> x;
    for (int i = 0; i < rec.size(); i++) {
        if(find(rec.begin(),rec.end(),x-rec[i])!=rec.end()) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
}