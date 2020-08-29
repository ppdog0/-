#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

int N, S;
pair<int, int> weeks[10001];

void solve() {
    long long total = 0;
    int i = 0, f = weeks[0].first;
    total += f * weeks[0].second;
    while(++i < N) {
        f = (f + S < weeks[i].first) ? f + S : weeks[i].first;
        total += f * weeks[i].second;
        f = weeks[i].first;
    }
    printf("%lld\n", total);
}

int main(void) {
    scanf("%d%d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &weeks[i].first, &weeks[i].second);
    }
    solve();
    return 0;
}

// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// int N,S,C[10005],Y[10005],pre;
// long long sum;
// int main()
// {
//     scanf("%d%d",&N,&S);
//     for(int i=1;i<=N;i++)
//         scanf("%d%d",&C[i],&Y[i]);
//     pre=C[1];
//     sum+=(pre*Y[1]);
//     for(int i=2;i<=N;i++)
//     {
//         pre=(C[i]<=pre+S)?C[i]:pre+S;
//         sum+=(pre*Y[i]);
//     }
//     printf("%lld",sum);
//     return 0;
// }