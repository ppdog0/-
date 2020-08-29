#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_N 21
#define MOVES 10
int W, H;
int r[MAX_N][MAX_N];
int x, y, m, n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int step, steps;

void dfs(int nx, int ny) {
    if (MOVES < step)
        return;

    for (int i = 0; i < 4; i++) {
        int c = nx + dx[i];
        int d = ny + dy[i];
        bool flag = false;

        while ( 0 <= c && c < H && 0 <= d && d < W && r[c][d] == 0) {
            flag = true;
            c += dx[i];
            d += dy[i];
        }
        if ( (c == m) && (d == n) ) {
            if( step < steps )
                steps = step;
        } else if ( 0 <= c && c < H && 0 <= d && d < W && flag ) {
            step++;
            r[c][d] = 0;
            dfs(c - dx[i], d - dy[i]);
            step--;
            r[c][d] = 1;
        }
    }
}

int main(void) {
    while( scanf("%d%d", &W, &H) && (W&&H) ) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &r[i][j]);
                if(r[i][j] == 2){
                    x = i;
                    y = j;
                } else if(r[i][j] == 3) {
                    m = i;
                    n = j;
                }
            }
            getchar();
        }
        r[x][y] = 0;
        step = 1;
        steps = 1000000;
        dfs(x, y);
        if( 10 < steps )
            printf("%d\n", -1);
        else
            printf("%d\n", steps);
    }
    return 0;
}