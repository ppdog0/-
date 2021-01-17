#include<iostream>

using namespace std;

const long long M = 1e10;

int N;
string T;

int main() {
    cin >> N >> T;
    string p;
    while(p.length() < N + 3)
        p.push_back('1'), p.push_back('1'), p.push_back('0');
    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        if(T == p.substr(i,N))
            ans += M - (i + N - 1) / 3;
    }
    cout << ans << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define pb push_back
// string s, p;
// int n;
// long long T = 1e10, ans;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin >> n >> s;
//     while (p.length() < n + 3)
//         p.pb('1'), p.pb('1'), p.pb('0');
//     for (int i = 0; i < 3; i++)
//         if (s == p.substr(i, n))
//             ans += T - (i - 1 + n) / 3;
//     cout << ans << endl;
//     return 0;
// }