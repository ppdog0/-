#include<iostream>
#include<string>

using namespace std;

int nums[20];
string N;

int main() {
    cin >> N;
    int n = N.size();
    for (int i = 0; i < n; i++)
        nums[i] = (int)N[i];
    int ans = 20;
    for (int i = (1 << n) - 1; 0 < i; i--) {
        int res = 0;
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1 ) {
                sum += nums[j];
                res++;
            }
        }
        if(sum % 3 == 0 && n - res < ans) {
            ans = n - res;
        }
    }
    if(ans==20)
        cout << -1 << endl;
    else
        cout << ans << endl;
}