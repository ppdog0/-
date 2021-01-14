#include<iostream>

using namespace std;

int W, H, N;

int main() {
    cin >> W >> H >> N;
    int x0 = 0, x1 = W, y0 = 0, y1 = H;
    int x, y, a;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> a;
        if(a==1) x0 = max(x, x0);
        if(a==2) x1 = min(x, x1);
        if(a==3) y0 = max(y, y0);
        if(a==4) y1 = min(y, y1);
    }
    cout << max(x1 - x0, 0) * max(y1 - y0, 0) << endl;   
    return 0;
}