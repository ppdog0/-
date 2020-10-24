#include<iostream>

using namespace std;

int count_keys(int x) {
    int ans = 0, res = 0;
    while(x) {
        x /= 10;
        res++;
        ans += res;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int n = x % 10;
        cout << (n - 1) * 10 + count_keys(x) << endl;
    }
}