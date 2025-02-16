#include "../Mybasic/mybasic.h"

//      LeetCode 754. 到达终点数字

//      链接：https://leetcode.cn/problems/reach-a-number/

//      在一根无限长的数轴上，你站在0的位置。终点在target的位置。
//      你可以做一些数量的移动 numMoves:
//      每次你可以选择向左或向右移动。
//      第 i 次移动 (从 i == 1 开始, 到 i == numMoves)，在选择的方向上走 i 步。
//      给定整数 target，返回 到达目标所需的 最小移动次数(即最小 numMoves) 。
//      示例 1:
//          输入: target = 2
//          输出: 3
//          解释:
//              第一次移动，从 0 到 1 。
//              第二次移动，从 1 到 -1 。
//              第三次移动，从 -1 到 2 。
//      示例 2:
//          输入: target = 3
//          输出: 2
//          解释:
//              第一次移动，从 0 到 1 。
//              第二次移动，从 1 到 3 。
//      提示:
//          -109 <= target <= 109
//          target != 0

int ReachNumber(int target);

int main()
{
    int target = GenerateRandomNum(-100000, 100000);
    int ans = ReachNumber(target);
    printf("到达 %d 所需的 最小 移动次数为 %d。\n", target, ans);
}

// 数学：
//   假设经历 k 次, k 次求和，dif = sum - target
//       dif == 0 或 dif 为 偶数 : 为 k
//       dif 为 奇 : 为 k + 1或2   
//          加的次数为 使得下一个k的sum - target 为偶数
// Time: O(N)
// Space: O(1)
int ReachNumber(int target)
{
    int t = abs(target);
    int k = 0;
    while (t > 0)
    {
        k++;
        t -= k;
    }
    return (t % 2 == 0) ? k : k + 1 + (k % 2);
}