#include<iostream>
#include<utility>
#include<vector>
#define INF 0x7fffffff

using namespace std;

int N;
vector<pair<int, int>> points;

int main() {
    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back(pair<int, int>(x, y));
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            float l1;
            int x1 = points[i].first, y1 = points[i].second;
            int x2 = points[j].first, y2 = points[j].second;
            if (x1 == x2)
                l1 = INF;
            else
                l1 = (float)(y2 - y1) / (x2 - x1);
            for (int k = j + 1; k < N; k++) {
                float l2;
                int x3 = points[k].first, y3 = points[k].second;
                if (x2 == x3)
                    l2 = INF;
                else
                    l2 = (float)(y2 - y3) / (x2 - x3);
                if(l1==l2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}