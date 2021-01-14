#include<iostream>

using namespace std;

int N, X;
string S;

int main() {
    cin >> N >> X >> S;
    int res = X;
    for (int i = 0; i < S.size(); i++) {
        if(S[i] == 'o')
            res++;
        if(S[i] == 'x') {
            res--;
            res = max(0, res);
        }
    }
    cout << res << endl;
}