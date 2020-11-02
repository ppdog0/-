#include<iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    long long x, y;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        sum += (x + y) * (y - x + 1) / 2;
    }
    cout << sum << endl;
}