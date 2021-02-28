#include<iostream>

using namespace std;

#include <iostream>

using namespace std;

//输出结果
void printRes(int *a, bool *index, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (index[i])
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

//检查最后k个位置是否已全变成0
bool hasDone(bool *index, int n, int k)
{
    for (int i = n - 1; i >= n - k; i--)
    {
        if (!index[i])
        {
            return false;
        }
    }
    return true;
}

void comb(int *a, int n, int k)
{
    bool *index = new bool[n]();
    //选中前k个位置
    for (int i = 0; i < k; i++)
    {
        index[i] = true;
    }
    printRes(a, index, n);

    while (!hasDone(index, n, k))
    {
        //从左到右扫描数组
        for (int i = 0; i < n - 1; i++)
        {
            //找到第一个“10”组合将其变成"01"组合
            if (index[i] && !index[i + 1])
            {
                index[i] = false;
                index[i + 1] = true;

                //将"01"组合左边的1移到最左边
                int count = 0;
                for (int j = 0; j < i; j++)
                {
                    if (index[j])
                    {
                        index[j] = false;
                        index[count++] = true;
                    }
                }
                printRes(a, index, n);
                break;
            }
        }
    }
    delete[] index;
}

int main() {
    int n, k;
    while(cin>>n>>k) {
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        comb(a, n, k);
    }
}

// #include <iostream>
// using namespace std;

// void dfs(int pos, int cnt, int n, int k, int a[], bool visited[])
// {
//     //已标记了k个数，输出结果
//     if (cnt == k)
//     {
//         for (int i = 0; i < n; i++)
//             if (visited[i])
//                 cout << a[i] << ' ';
//         cout << endl;
//         return;
//     }

//     //处理到最后一个数，直接返回
//     if (pos == n)
//         return;

//     //如果a[pos]没有被选中
//     if (!visited[pos])
//     {
//         //选中a[pos]
//         visited[pos] = true;
//         //处理在子串a[pos+1, n-1]中取出k-1个数的子问题
//         dfs(pos + 1, cnt + 1, n, k, a, visited);
//         //回溯
//         visited[pos] = false;
//     }
//     //处理在子串a[pos+1, n-1]中取出k个数的问题
//     dfs(pos + 1, cnt, n, k, a, visited);
// }
// int main()
// {
//     int i, n, k;
//     while (cin >> n >> k, n || k)
//     {
//         int *a = new int[n];
//         bool *visited = new bool[n];
//         for (i = 0; i < n; i++)
//         {
//             a[i] = i + 1;
//             visited[i] = false;
//         }
//         dfs(0, 0, n, k, a, visited);
//         delete[] a;
//         delete[] visited;
//     }
//     getchar();
//     return 0;
// }
