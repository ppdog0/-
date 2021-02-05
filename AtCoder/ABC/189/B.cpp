#include <iostream>

using namespace std;

int N, X;

int main() {
    cin >> N >> X;

    int v, p;
    int res = X * 100;
    for (int i = 0; i < N; i++) {
        cin >> v >> p;
        res -= v * p;
        if (res < 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}