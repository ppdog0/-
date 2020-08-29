// #include<stdio.h>
// #include<stdlib.h>
// #include<algorithm>

// using namespace std;

// const int MAX_N = 10;

// int N, S;
// int numbers[MAX_N], tempt[MAX_N];

// void solve() {
//     do {
//         for (int i = 0; i < N;i++)
//             tempt[i] = numbers[i];
//         for (int i = N - 1; 0 < i; i--)
//             for (int j = 0; j < i; j++) {
//                 tempt[j] = tempt[j] + tempt[j + 1];
//             }
//         if(tempt[0] == S)
//             break;
//     } while (next_permutation(numbers, numbers + N));
//     for (int i = 0; i < N; i++)
//         printf("%d ", numbers[i]);
//     printf("\n");
// }

// int main(void) {
//     scanf("%d%d", &N, &S);
//     for (int i = 0; i < N; i++)
//         numbers[i] = i + 1;

//     solve();
//     return 0;
// }

#include<stdio.h>
#include<algorithm>

using namespace std;

const int MAX_N = 10;

int N, S;
int numbers[MAX_N], cnt[MAX_N][MAX_N];

inline int dot(int a[], int b[], int n) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += a[i] * b[i];
    return ret;
}

int main(void) {
    cnt[0][0] = 1;
    cnt[1][0] = cnt[1][1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        cnt[i][0] = 1;
        for (int j = 1; j < i + 1; j++)
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];
    }

        scanf("%d%d", &N, &S);
    for (int i = 0; i < N; i++)
        numbers[i] = i + 1;

    do{
        if(dot(numbers,cnt[N-1],N) == S)
            break;
    } while (next_permutation(numbers, numbers + N));

    for (int i = 0; i < N; i++)
        printf("%d ", numbers[i]);

    printf("\n");
    return 0;
}