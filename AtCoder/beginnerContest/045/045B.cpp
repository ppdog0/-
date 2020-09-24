#include<iostream>
#include<string>

using namespace std;

string SA, SB, SC;

int main() {
    cin >> SA >> SB >> SC;
    char c = SA.front();
    SA.erase(0, 1);
    while(true) {
        if(c == 'a') {
            if(SA.empty())
                break;
            c = SA.front();
            SA.erase(0, 1);
        } else if (c == 'b') {
            if(SB.empty())
                break;
            c = SB.front();
            SB.erase(0, 1);
        } else {
            if(SC.empty())
                break;
            c = SC.front();
            SC.erase(0, 1);
        }
    }
    cout << (char)(c - 32) << endl;
    return 0;
}