#include<iostream>
#include<map>

using namespace std;

long long N;
map<int, int> record;

int main() {
    cin >> N;
    int a = 3, sum = 1;
    for (int i = 0; i <= 38; i++) {
        if(a>N)
            break;
        record[a] = sum;
        a *= 3;
        sum++;
    }
    int b = 5, tot = 1;
    for (int i = 0; i <= 26; i++) {
        if(b>N)
            break;
        if(record.count(N-b) == true) {
            cout << record[N - b] << " " << tot << endl;
            return 0;
        }
        b *= 5;
        tot++;
    }
    cout << "-1" << endl;
}