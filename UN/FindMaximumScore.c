#include "../Mybasic/mybasic.h"

//      LeetCode 3282. 到达数组末尾的最大得分

//      链接：https://leetcode.cn/problems/reach-end-of-array-with-max-score/

//      给你一个长度为 n 的整数数组 nums。
//      你的目标是从下标 0 出发，到达下标 n - 1 处。每次你只能移动到 更大 的下标处。
//      从下标 i 跳到下标 j 的得分为 (j - i) * nums[i] 。
//      请你返回你到达最后一个下标处能得到的 最大总得分 。
//      示例 1：
//          输入：nums = [1,3,1,5]
//          输出：7
//          解释：
//              一开始跳到下标 1 处，然后跳到最后一个下标处。总得分为 1 * 1 + 2 * 3 = 7
//      示例 2：
//          输入：nums = [4,3,1,3,2]
//          输出：16
//          解释：
//              直接跳到最后一个下标处。总得分为 4 * 4 = 16 。
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 105

long long FindMaximumScore(int* nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    long long ans = FindMaximumScore(vec, n);
    printf("到达最后一个下标处能得到的 最大总得分 为: %d\n", ans);
    FreeVec(vec);
}


long long FindMaximumScore(int* nums, int numsSize)
{

}