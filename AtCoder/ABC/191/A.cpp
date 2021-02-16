#include<iostream>

using namespace std;

int v, t, s, d;

int main() {
    cin >> v >> t >> s >> d;
    if(d<t*v || s*v<d)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}