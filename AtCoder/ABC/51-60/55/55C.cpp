/*
 * Created Date: Friday, October 2nd 2020, 10:31:17 am
 * Author: ppdog
 * 
 */

// M + (M-2*N) / 4

#include<iostream>

using namespace std;

long long n, m;

int main() {
    cin >> n >> m;
    cout << (n <= m/2 ? n + (m-(n*2))/4 : m/2) << endl;
}