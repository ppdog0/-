#include<iostream>
#include<bitset>

using namespace std;
const int max_n = 52;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        bitset<max_n> nums;
        cin >> n;
        int a, start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (start==-1 && a==1)
                start = i;
            if(a==1) {
                nums.set(i);
                end = max(end, i);
            }
        }
        cout << (end - start + 1) - nums.count() << endl;
    }
}