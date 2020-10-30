#include<iostream>

using namespace std;

int N;
int l = 101;

int main() {
    cin >> N;
    int x;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        sum += x;
        if (x % 10 != 0)
            l = min(l, x);
    }
    if(l == 101)
        cout << 0 << endl;
    else if (sum%10!=0)
        cout << sum << endl;
    else
        cout << sum - l << endl;
}