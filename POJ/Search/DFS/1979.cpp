#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_N 20
int W, H;
char a[MAX_N][MAX_N];
int res=0;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int x, y;

void dfs(int nx, int ny) {
    a[nx][ny]='#';
    res++;
    for (int i = 0; i < 4; i++) {
        x = nx + dx[i];
        y = ny + dy[i];
        if(0 <= x && x < H && 0 <= y && y < W && a[x][y] == '.')
            dfs(x, y);
    }
}

int main(void) {
    int nx, ny;
    while ( scanf("%d%d\n", &W, &H) && (W||H) )
    {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%c", &a[i][j]);
                if(a[i][j] == '@') {
                    nx = i; ny = j;
                }
            }
            getchar();
        }
        a[nx][ny] = '.'; dfs(nx, ny);
        printf("%d\n", res);
        res = 0;
    }

    return 0;
}