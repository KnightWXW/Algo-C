#include "../Mybasic/mybasic.h"

//      LeetCode 605. 种花问题

//      链接：https://leetcode.cn/problems/can-place-flowers/

//      假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
//      可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//      给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，
//      其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，
//      能否在不打破种植规则的情况下种入 n 朵花？
//      能则返回 true ，不能则返回 false。
//      示例 1：
//          输入：flowerbed = [1,0,0,0,1], n = 1
//          输出：true
//      示例 2：
//          输入：flowerbed = [1,0,0,0,1], n = 2
//          输出：false
//      提示：
//          1 <= flowerbed.length <= 2 * 104
//          flowerbed[i] 为 0 或 1
//          flowerbed 中不存在相邻的两朵花
//          0 <= n <= flowerbed.length

bool CanPlaceFlowers(int *flowerbed, int flowerbedSize, int n);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int flowers = GenerateRandomNum(1, n / 2 + 1);
    int *arr = GenerateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    PrintVecElement(arr, n);
    bool ans = CanPlaceFlowers(arr, n, flowers);
    printf("能否在不打破种植规则的情况下种入 %d 朵花？？？\n", flowers);
    FreeVec(arr);
    PrintBool(ans);
}

// 贪心：
// Time: O(N)
// Space: O(1)
bool CanPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int ans = 0;
    for (int i = 0; i < flowerbedSize; i++)
    {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbedSize - 1 || flowerbed[i + 1] == 0))
        {
            ans++;
            flowerbed[i] = 1;
        }
    }
    return n <= ans;
}