// 踩坑 memset初始值0/-1/0x3f3f3f，不能是其他值，可以用fill

#include<iostream>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<map<char, int>> record(n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for(auto index:str) {
            record[i][index]++;
        }
    }
    int num[26];
    fill(num, num+26, 51);
    int letter[26]={0};
    for(auto v:record) {
        for(auto m : v) {
            int c = m.first - 'a';
            num[c] = min(num[c], m.second);
            ++letter[c];
        }
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
        if(51 <= num[i] || letter[i] < n)
            continue;
        while(num[i]--)
            ans += (char)(i + 'a');
    }
    cout << ans << endl;
}