#include<iostream>
using namespace std;

// 排列
void perm(int start, int end, int* a) {
    if (start == end) {
        for (int i = 0; i < end; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < end; i++) {
        swap(a[start], a[i]);
        perm(start + 1, end, a);
        swap(a[i], a[start]);
    }
}

int main() {
    int n;
    while(cin >> n) {
        int a[n];
        for(int &x:a)
            cin >> x;
        perm(0, n, a);
    }
}