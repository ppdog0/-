typedef long long ll;

//输入
int n, a[MAX_N];

void solve() {
    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += j - sum(a[j]);
        add(a[j], 1);
    }
    printf("%lld\n", ans);
}