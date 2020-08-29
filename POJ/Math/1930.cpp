#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
ll GCD, LCM;
int main() {
    while(scanf("%d%d", &GCD, &LCM) != EOF){
        if(GCD == LCM)
        {
            printf("%llu, %llu\n", GCD, LCM);
            continue;
        }
        ll n = GCD, m = LCM;
        minn = INF;
        ct = cnt = 0;
        ans = m / n;
    }
    return 0;
}