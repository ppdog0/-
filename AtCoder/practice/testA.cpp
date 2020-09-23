#include<cstdio>
#include<iostream>

using namespace std;

int a, b, c;
char s[101];

int main() {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", s);
    printf("%d %s\n", a + b + c, s);
    return 0;
}