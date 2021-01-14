#include<iostream>
#include<set>

using namespace std;

long long N;
set<long long> q;

int main() {
    cin >> N;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            q.insert(i);
            q.insert(N / i);
        }
    }
    for (auto p : q) {
        cout << p << endl;
    }
    return 0;
}