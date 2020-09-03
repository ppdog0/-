#include<vector>
using namespace std;

// 能在时间T从该门逃脱的人，二分搜索T
// 对于最小的t，t时间内只有一人能够从该门逃脱
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

// 输入
int X, Y;
char field[MAX_X][MAX_Y + 1]; // 不要忘记保存\0所需的空间(字符串)

vector<int> dX, dY; // 门的坐标
vector<int> pX, pY; // 人的坐标
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y]; // 最近距离

// 判断所有人是否能够在时间t以内安全逃离
bool C(int t) {
    int d = dX.size(), p = pX.size();
}