#include<iostream>
#include<vector>
#include<set>

using namespace std;

int N, M;

int main() {
    cin >> N;
    long long sum = 0;
    vector<long long> problems(N);
    for (int i = 0; i < N; i++) {
        cin >> problems[i];
        sum += problems[i];
    }
    cin >> M;
    int num;
    long long time;
    vector<long long> record;
    while (M--) {
        cin >> num >> time;
        //record.insert(sum - (problems[num - 1] - time));
        record.push_back(sum - (problems[num - 1] - time));
    }
    for (auto res : record)
        cout << res << endl;
    return 0;
}