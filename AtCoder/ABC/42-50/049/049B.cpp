#include<iostream>

using namespace std;

int H, W;

int main() {
    string s;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> s;
        cout << s << endl;
        cout << s << endl;
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char s[10000];
//     int a,b,i,j;
//     while(~scanf("%d %d",&a,&b))
//     {
//          for(i=0;i<a;i++)
//          {
//              scanf("%s",s);
//              printf("%s\n",s);
//              printf("%s\n",s);
//          }
//     }
//     return 0;
// }
