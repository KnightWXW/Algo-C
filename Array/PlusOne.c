#include "../Mybasic/mybasic.h"

//      LeetCode 66. 加一

//      链接：https://leetcode.cn/problems/plus-one/

//      给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//      最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//      你可以假设除了整数 0 之外，这个整数不会以零开头。
//      示例 1：
//          输入：digits = [1,2,3]
//          输出：[1,2,4]
//          解释：输入数组表示数字 123。
//      示例 2：
//          输入：digits = [4,3,2,1]
//          输出：[4,3,2,2]
//          解释：输入数组表示数字 4321。
//      示例 3：
//          输入：digits = [0]
//          输出：[1]
//      提示：
//          1 <= digits.length <= 100
//          0 <= digits[i] <= 9

#define NUMBER_TEN 10

int *PlusOne(int *digits, int digitsSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 9, n);
    PrintVecElement(vec, n);
    int l = 0;
    int *ans = PlusOne(vec, n, &l);
    printf("该数的基础上加一后数组为：\n");
    PrintVecElement(ans, n);
    FreeVec(ans);
}

// 数组操作：
// Time: O(N)
// Space: O(N)
int *PlusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        digits[i]++;
        if (digits[i] == NUMBER_TEN)
        {
            digits[i] = 0;
        }
        else
        {
            *returnSize = digitsSize;
            return digits;
        }
    }
    // 全为 9 的情况:
    int *ans = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ans, 0, sizeof(int) * (digitsSize + 1));
    ans[0] = 1;
    *returnSize = digitsSize + 1;
    return ans;
}