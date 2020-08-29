// #include<stdio.h>
// #include<stdbool.h>
// #include<algorithm>

// using namespace std;

// const int MAX_N = 25000;

// int N, T;
// int cows[MAX_N][2];

// void solve() {
//     int t = 1, res = 0;
//     for (int i = 0; (i < N) && (t < T) ; i++) {
//         if( (t <= cows[i][0]) && (cows[i][1] <= t) ) {
//             t = cows[i][0];
//             res++;
//         } else if(t < cows[i][1]) {
//             res = -1;
//             break;
//         }
//     }
//     printf("%d\n", res);
// }

// int main(void) {
//     scanf("%d%d", &N, &T);
//     for (int i = 0; i < N;i++) {
//         scanf("%d%d", &cows[i][1], &cows[i][0]);
//     }
//     //sort(cows, cows + N);
//     solve();
//     return 0;
// }

// bool cmp(pair<int, int> a,pair<int, int> b)
// {
//     return a.first!=b.first ? a.first<b.first : a.second>=b.second;
// }

#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
int N, T, ans;
pair<int, int> itv[25005];
int main(void) {
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N;i++)
        scanf("%d%d", &itv[i].first, &itv[i].second);
    sort(itv, itv + N);
    int i = -1, t = 0;
    while(t < T) {
        int mr = -1;
        while(itv[++i].first <= t+1)
            mr = max(mr, itv[i].second);
        if(mr == -1) {
            ans = -1;
            break;
        }
        t = mr;
        ans++;
        i--;
    }
    printf("%d\n",ans);
    return 0;
}

// #include<stdio.h>
// #include<utility>
// #include<algorithm>
// using namespace std;
// int N, T, ans;
// pair<int, int> itv[25005];
// int main(void) {
//     scanf("%d%d", &N, &T);
//     for (int i = 1; i <= N;i++)
//         scanf("%d%d", &itv[i].first, &itv[i].second);
//     sort(itv+1, itv + N+1);
//     int l=0,i=0;//这里l处置为0
//     while(l<T)
//     {
//         int maxr=-1;
//         while(itv[++i].first<=l+1)//小于l+1而不是小于l
//             maxr=max(itv[i].second,maxr);
//         if(maxr==-1){
//             ans = -1;
//             break;
//         } //如果不能找到可以继续覆盖的牛就结束
//         ans++;
//         l=maxr;//更新最右边界
//         i--;
//     }
//     printf("%d\n",ans);
//     return 0;
// }

// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int N,T,ans;
// struct c{int l,r;}cow[25005];
// bool cmp(c a,c b){return a.l<b.l;}
// int main()
// {
//     scanf("%d%d",&N,&T);
//     for(int i=1;i<=N;i++)
//         scanf("%d%d",&cow[i].l,&cow[i].r);
//     sort(cow+1,cow+N+1,cmp);
//     int l=0,i=0;//这里l处置为0
//     while(l<T)
//     {
//         int maxr=-1,maxri;
//         while(cow[++i].l<=l+1)//小于l+1而不是小于l
//             maxr=cow[i].r>maxr?cow[maxri=i].r:maxr;
//         if(maxr==-1){printf("-1");return 0;}//如果不能找到可以继续覆盖的牛就结束
//         ans++;
//         i--;//下次找牛从上次失败的地方开始
//         l=maxr;//更新最右边界
//     }
//     printf("%d",ans);
//     return 0;
// }