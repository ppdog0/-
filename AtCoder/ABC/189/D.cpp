#include<iostream>
#include<cmath>

using namespace std;

int n;
string s[61];

long long f(int n) {
    if(n == 0)
        return 1;
    if (s[n] == "AND")
        return f(n - 1);
    else
        return (1ll << n) + f(n - 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cout << f(n) << endl;
}