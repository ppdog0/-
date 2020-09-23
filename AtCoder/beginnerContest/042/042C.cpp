#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int N, K;
vector<bool> record(10, false);

int main() {
    scanf("%d%d", &N, &K);
    int num;
    for (int i = 0; i < K; i++) {
        cin >> num;
        record[num] = true;
    }
    for (int i = N;;i++) {
        int j = i;
        bool flag = true;
        while(0 < j) {
            if(record[j % 10]) {
                flag = false;
                break;
            }
            j /= 10;
        }
        if(flag) {
            num = i;
            break;
        }
    }

    printf("%d\n", num);
    return 0;
}