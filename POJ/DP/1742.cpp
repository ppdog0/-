#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, v[101], num[101], judge[100001], use[100001], sum;
int main() {
    while( scanf("%d%d", &n, &m) && (n&&m) ) {
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        memset(judge, 0, sizeof(judge));
        sum = 0;
        judge[0] = 1;
        for (int i = 0; i < n; i++) {
            memset(use, 0, sizeof(use));
            for (int j = v[i]; j <= m; j++) {
                if(judge[j-v[i]]==1&&use[j-v[i]]<num[i]&&judge[j]==0) {
                    judge[j] = 1;
                    sum++;
                    use[j] = use[j - v[i]] + 1;
                }
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}