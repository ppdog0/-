#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5+10;
int N, M;
int x[MAX_N];

bool C(int d) {
    int last = 0;
    for (int i = 1; i < M; i++)
    {
        int crt = last + 1;
        while (crt < N && x[crt] - x[last]<d)
            crt++;
        if(crt==N)
            return false;
        last = crt;
    }
    return true;
}

void solve() {
    sort(x, x + N);

    int lb = 1, ub = x[N-1]-x[0];
    while(ub-lb>1)
    {
        int mid = (lb + ub) >> 1;
        if(C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", lb);
}

int main() {
    while(~scanf("%d%d",&N,&M))
    {
        for(int i = 0; i < N; i++)
            scanf("%d",&x[i]);
        solve();
    }
    return 0;
}