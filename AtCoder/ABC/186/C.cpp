#include<iostream>

using namespace std;

// string to_oct(int n) {
//     string s;
//     while(n) {
//         s = to_string(n % 8) + s;
//         n /= 8;
//     }
//     return s;
// }

bool checkdec(int x) {
    while(x) {
        if (x%10==7)
            return false;
        x /= 10;
    }
    return true;
}

bool checkoct(int x) {
    while(x) {
        if (x%8==7)
            return false;
        x /= 8;
    }
    return true;
}

int N;

int main()
{
    cin >> N;
    int ans = N;
    for (int i = 1; i <= N; i++) {
        if(!checkdec(i))
            --ans;
        else if (!checkoct(i))
            --ans;
    }
    cout << ans << endl;
}
