#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> record;

int main() {
    cin >> N;
    int x;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        record.push_back(x);
    }
    while (1 < N) {
        int k1 = 0, k2 = 1;
        if (record[k2] < record[k1])
            swap(k1, k2);
        for (int i = 2; i < N; i++) {
            if(record[i] < record[k1]) {
                k2 = k1;
                k1 = i;
            } else if (record[i] < record[k2])
                k2 = i;
        }
        int l = record[k1] + record[k2];
        ans += l;

        if(k1 == N - 1)
            swap(k1, k2);
        record[k1] = l;
        record[k2] = record[--N];
    }

    cout << ans << endl;
}