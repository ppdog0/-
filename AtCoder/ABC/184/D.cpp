#include<iostream>
#include<iomanip>

using namespace std;

int a, b, c;
double dp[101][101][101];

double f(int a, int b, int c) {
    if (dp[a][b][c])
        return dp[a][b][c];
    if (a==100||b==100||c==100)
        return 0;
    double ans = 0;
    ans += (f(a + 1, b, c) + 1) * a / (a + b + c);
    ans += (f(a, b + 1, c) + 1) * b / (a + b + c);
    ans += (f(a, b, c + 1) + 1) * c / (a + b + c);
    return dp[a][b][c] = ans;
}

int main() {
    cin >> a >> b >> c;
    cout << fixed << setprecision(9) << f(a, b, c) << endl;
}