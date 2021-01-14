#include<iostream>

using namespace std;

string str;

int main() {
    cin >> str;
    int N = str.size(), num = 0;
    bool check = true;

    while(num < N) {
        if(str.substr(num, 6) == "eraser")
            num += 6;
        else if(str.substr(num, 5) == "erase")
            num += 5;
        else if(str.substr(num, 7) == "dreamer" && str.substr(num+5, 5) != "erase")
            num += 7;
        else if(str.substr(num, 5) == "dream")
            num += 5;
        else {
            check = false;
            break;
        }
    }
    if(check)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}