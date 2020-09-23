#include<cstdio>
#include<algorithm>

using namespace std;

int nums[3];

int main() {
    scanf("%d%d%d", &nums[0], &nums[1], &nums[2]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2 - i; j++)
            if (nums[j+1] < nums[j])
                swap(nums[j], nums[j + 1]);
    if(nums[0]==5&&nums[1]==5&&nums[2]==7)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}