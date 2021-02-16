#include<iostream>

using namespace std;

int h, w;

int main() {
    cin >> h >> w;
    char sqr[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> sqr[i][j];
    int m, n;
    int ans = 0;

    n = 1;
    while(n < w) {
        m = 1;
        while (m < h-1) {
            if (sqr[m][n] == '#' && sqr[m][n - 1] == '.') {
                ans++;
                while (sqr[++m][n] == '#')
                    ;
            }
            if (sqr[m][n] == '.' && sqr[m][n-1]=='#') {
                ans++;
                while(sqr[++m][n]=='.')
                    ;
            }
            m++;
        }
        n++;
    }

    m = 1;
    while(m < h) {
        n = 1;
        while (n < w-1) {
            if (sqr[m][n] == '#' && sqr[m-1][n] == '.') {
                ans++;
                while (sqr[m][++n] == '#')
                    ;
            }
            if (sqr[m][n] == '.' && sqr[m-1][n] == '#') {
                ans++;
                while (sqr[m][++n] == '.')
                    ;
            }
            n++;
        }
        m++;
    }

    cout << ans << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long h, w, ans = 0;
//     cin >> h >> w;
//     char s[h][w];
//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//             cin >> s[i][j];
//     }
//     for (int i = 0; i < h - 1; i++)
//     {
//         for (int j = 0; j < w - 1; j++)
//         {
//             long long c = 0;
//             for (int i1 = 0; i1 < 2; i1++)
//             {
//                 for (int j1 = 0; j1 < 2; j1++)
//                     if (s[i + i1][j + j1] == '#')
//                         c++;
//             }
//             if (c == 1 || c == 3)
//                 ans++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
