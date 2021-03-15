#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const int ref[10] = {0,1,5,-1,-1,2,-1,-1,8,-1};

void tranf(int time[], int h, int m) {
    int a = h % 10, b = h / 10;
    int c = m % 10, d = m / 10;
    time[0] = b, time[1] = a, time[2] = d, time[3] = c;
}

bool valid(int time[],int h, int m) {
    for (int i = 0; i < 4; i++) {
        if (time[i] == -1)
            return false;
    }
    int hour = time[0] * 10 + time[1];
    int min = time[2] * 10 + time[3];
    if (h <= hour || m <= min)
        return false;
    return true;
}

void solve() {
    int h, m;
    cin >> h >> m;
    string a;
    cin >> a;
    int hour = stoi(a.substr(0, 2));
    int min = stoi(a.substr(3, 2));

    int time[4], k = 0;
    tranf(time, hour, min);

    int rev[4] = {-1};

    for (int i = 0; i < 4; i++) {
        rev[i] = ref[time[3 - i]];
    }

    while (!valid(rev, h, m)) {
        int hour = time[0] * 10 + time[1];
        int min = time[2] * 10 + time[3];
        bool cry = false;
        if (min == m - 1) {
            min = 0;
            cry = true;
        } else {
            min++;
        }
        if (cry) {
            if (hour == h - 1)
                hour = 0;
            else
                hour++;
        }

        tranf(time, hour, min);
        for (int i = 0; i < 4; i++) {
            rev[i] = ref[time[3 - i]];
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << time[i];
        if (i == 1)
            cout << ":";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}