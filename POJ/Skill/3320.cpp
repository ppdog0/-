#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int MAX_P = 1e6 + 10;
//输入
int P;
int a[MAX_P];

void solve() {
    //计算全部知识点总数
    set<int> all;
    for (int i = 0; i < P; i++)
    {
        all.insert(a[i]);
    }
    int n = all.size();

    //尺取法
    int s = 0, t = 0, num = 0;
    map<int, int> count; //知识点->出现次数的映射
    int res = P;
    for (;;)
    {
        while(t<P&&num<n)
            if(count[a[t++]]++ == 0)
                num++;
        if(num<n)
            break;
        res = min(res, t - s);
        if(--count[a[s++]]==0)
        {
            num--;
        }
    }
    printf("%d\n", res);
}

int main() {
    scanf("%d", &P);
    for (int i = 0; i < P; i++)
        scanf("%d", &a[i]);
    solve();
    return 0;
}