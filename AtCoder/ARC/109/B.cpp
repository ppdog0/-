#include<iostream>

using namespace std;

long long n;

int main() {
    cin >> n;
    long long l = 1, r = n;
    long long ans = (n - l + 2) / 3;
    cout << n - ans << endl;
}