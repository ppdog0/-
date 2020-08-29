#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int MAX_N = 10;
const int INF = 1000000;

int N, n;
int numbers[MAX_N];

int power(int i, int j) {
    int sum = 0;
    for(int m =i;m<j;m++)
        sum = sum*10+numbers[m];
    return sum;
}


void EXS() {
    int ans = INF;
    int k = n / 2;

    do {
        if(numbers[0] == 0 || numbers[k] == 0)
            continue;
        int a = power(0,k), b = power(k,n);
        ans = min(ans, abs(a-b));
    } while(next_permutation(numbers,numbers+n));

    if(n==2)
        ans = abs(numbers[0]-numbers[1]);
    printf("%d\n", ans);
}

int main(void) {
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        char c;
        n = 0;
        while ((c = getchar()) != '\n')
            if(c != ' ')
                numbers[n++] = c - '0';
        EXS();
    }

    return 0;
}