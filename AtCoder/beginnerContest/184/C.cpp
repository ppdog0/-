#include<iostream>

using namespace std;

int r1, c1, r2, c2;

bool check() {
    if (r1 + c1 == r2 + c2)
        return true;
    else if(r1 - c1 == r2 - c2)
        return true;
    else if (abs(r1-r2) + abs(c1-c2) <= 3)
        return true;
    return false;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    int res = 0;
    while(!check()) {
        
    }
    cout << res << endl;
}