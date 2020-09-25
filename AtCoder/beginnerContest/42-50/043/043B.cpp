#include<iostream>
#include<string>
#include<stack>
using namespace std;

string str;

int main() {
    string ans;
    cin >> str;
    for(auto s : str) {
        switch(s) {
            case '0':
            case '1':
                ans += s;
                break;
            case 'B':
                if(ans.size())
                    ans.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}