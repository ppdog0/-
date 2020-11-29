#include<iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int x, y;
    int n = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x == y)
            n++;
        else
            n = 0;
        if (n == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}