#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;

int main() {
    scanf("%d%d", &N, &L);
    vector<string> strs(N);
    for (int i = 0; i < N; i++)
        cin >> strs[i];
    sort(strs.begin(), strs.end());

    string ans;
    for (int i = 0; i < N; i++)
        ans += strs[i];

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int N, L;
//   cin >> N >> L;
//   vector<string> S(N);
//   for (int i = 0; i < N; i++)
//     cin >> S[i];
//   sort(S.begin(), S.end());
//   string Ans;
//   for (int i = 0; i < N; i++)
//     Ans += S[i];
//   cout << Ans << endl;
//   return 0;
// }


// bool comp(string str1, string str2) {
//     int i = 0, j = 0;
//     while(i < str1.size() && j < str2.size()) {
//         if(str1[i] < str2[j])
//             return true;
//         else if (str2[j++] < str1[i++])
//             return false;
//     }
//     if (i == str1.size())
//         return true;
//     return false;
// }

// void insert_string(int lo, int hi, string str) {
//     int mid = (lo + hi) >> 1;
//     if (comp(strs[mid], str)) {
//         if (hi - lo == 1) {
//             strs.insert(lo, 1, (char)str[0]);
//         } else {
//             insert_string(lo, mid, str);
//         }
//     } else {
//         if (hi - lo <= 2) {
//             strs.insert(hi, 1, (char)str[0]);
//         } else {
//             insert_string(mid + 1, hi, str);
//         }
//     }
// }