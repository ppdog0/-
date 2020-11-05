#include<iostream>

using namespace std;

int L, N;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> L >> N;
        int x, minD = 0, maxD = 0;
        for (int i = 0; i < N; i++) {
            cin >> x;
            minD = max(minD, min(x, L - x));
            maxD = max(maxD, max(x, L - x));
        }
        cout << minD << " " << maxD << endl;
    }
}