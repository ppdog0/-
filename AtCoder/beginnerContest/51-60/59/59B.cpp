#include<iostream>
#include<stack>

using namespace std;

long long A, B;
stack<int> sa, sb;

int count_A(long long x) {
    int digit = 0;
    while(x) {
        digit++;
        sa.push(x % 10);
        x /= 10;
    }
    return digit;
}

int count_B(long long x) {
    int digit = 0;
    while(x) {
        digit++;
        sb.push(x % 10);
        x /= 10;
    }
    return digit;
}

int main() {
    cin >> A >> B;
    int da = count_A(A), db = count_B(B);
    if(da<db)
        cout << "LESS" << endl;
    else if(db<da)
        cout << "GREATER" << endl;
    else {
        while(!sa.empty()) {
            int na = sa.top(); sa.pop();
            int nb = sb.top(); sb.pop();
            if(na<nb) {
                cout << "LESS" << endl;
                return 0;
            } else if (nb<na) {
                cout << "GREATER" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     string A, B;
//     cin >> A;
//     cin >> B;
//     if (A == B){
//         cout << "EQUAL" << endl;
//     }else if(A.length() > B.length()){
//         cout << "GREATER" << endl;
//     }else if(A.length() < B.length()){
//         cout << "LESS" << endl;
//     }else{
//         for(int i = 0; i < A.length(); i++){
//             if(A[i] > B[i]){
//                 cout << "GREATER" << endl;
//                 break;
//             }else if(A[i] < B[i]){
//                 cout << "LESS" << endl;
//                 break;
//             }
//         }
//     }
// }
