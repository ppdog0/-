#include<iostream>
#include<iomanip>

using namespace std;

double m, n, x, y;

int main() {
    cin >> m >> n >> x >> y;
    n = -n;
    double k = (y - n) / (x - m);
    double r = -(y / k) + x;
    cout << fixed<<setprecision(8) << r;
}