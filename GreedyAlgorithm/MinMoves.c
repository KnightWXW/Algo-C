#include "../Mybasic/mybasic.h"

//      LeetCode 2139. 得到目标值的最少行动次数

//      链接：https://leetcode.cn/problems/minimum-moves-to-reach-target-score/

//      你正在玩一个整数游戏。从整数 1 开始，期望得到整数 target 。
//      在一次行动中，你可以做下述两种操作之一：
//          递增，将当前整数的值加 1（即，x = x + 1）。
//          加倍，使当前整数的值翻倍（即，x = 2 * x）。
//      在整个游戏过程中，你可以使用 递增 操作 任意 次数。
//      但是只能使用 加倍 操作 至多 maxDoubles 次。
//      给你两个整数 target 和 maxDoubles，
//      返回从 1 开始得到 target 需要的最少行动次数。
//      示例 1：
//          输入：target = 5, maxDoubles = 0
//          输出：4
//          解释：一直递增 1 直到得到 target。
//      示例 2：
//          输入：target = 19, maxDoubles = 2
//          输出：7
//          解释：最初，x = 1 。
//              递增 3 次，x = 4 。
//              加倍 1 次，x = 8 。
//              递增 1 次，x = 9 。
//              加倍 1 次，x = 18 。
//              递增 1 次，x = 19 。
//      示例 3：
//          输入：target = 10, maxDoubles = 4
//          输出：4
//          解释：
//              最初，x = 1 。
//              递增 1 次，x = 2 。
//              加倍 1 次，x = 4 。
//              递增 1 次，x = 5 。
//              加倍 1 次，x = 10 。
//      提示：
//          1 <= target <= 109
//          0 <= maxDoubles <= 100

int MinMoves_A(int target, int maxDoubles);
int MinMoves_B(int target, int maxDoubles);

int main()
{
    int target = GenerateRandomNum(1, 10000000);
    int maxDoubles = GenerateRandomNum(0, 100);
    int ansA = MinMoves_A(target, maxDoubles);
    int ansB = MinMoves_B(target, maxDoubles);
    printf("target 和 maxDoubles 分别为 %d 与 %d 时，从 1 开始得到 target 需要的最少行动次数为 %d。\n", target, maxDoubles, ans);
}

// 贪心算法: 反向模拟(超时)
// Time: O(N)
// Space: O(1)
int MinMoves_A(int target, int maxDoubles)
{
    int move = 0;
    while (target != 1)
    {
        if ((target & 1) == 0 && maxDoubles > 0)
        {
            target >>= 1;
            maxDoubles--;
        }
        else
        {
            target -= 1;
        }
        move++;
    }
    return move;
}

// 贪心算法: 反向操作
// Time: O(N)
// Space: O(1)
int MinMoves_B(int target, int maxDoubles)
{
    int move = 0;
    while (target != 1 && maxDoubles > 0)
    {
        if ((target & 1) == 0)
        {
            target >>= 1;
            maxDoubles--;
        }
        else
        {
            target -= 1;
        }
        move++;
    }
    move += (target - 1);
    return move;
}