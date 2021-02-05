#include<iostream>

using namespace std;

int main() {
    char C1, C2, C3;
    cin >> C1 >> C2 >> C3;
    if (C1 == C2 && C2 == C3) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }
}