#include<iostream>

using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    int a;
    string ans = "";
    for (int i = 0; i < n; i++) {
        cin >> a;
        if(a!=x)
            ans += to_string(a) + " ";
    }
    cout << ans << endl;
}