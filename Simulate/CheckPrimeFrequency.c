#include "../Mybasic/mybasic.h"

//      LeetCode 3591. 检查元素频次是否为质数

//      链接：https://leetcode.cn/problems/check-if-any-element-has-prime-frequency/

//      给你一个整数数组 nums。
//      如果数组中任一元素的 频次 是 质数，返回 true；否则，返回 false。
//      元素 x 的 频次 是它在数组中出现的次数。
//      质数是一个大于 1 的自然数，并且只有两个因数：1 和它本身。
//      示例 1：
//          输入： nums = [1,2,3,4,5,4]
//          输出： true
//          解释：
//              数字 4 的频次是 2，而 2 是质数。
//      示例 2：
//          输入： nums = [1,2,3,4,5]
//          输出： false
//          解释：
//              所有元素的频次都是 1。
//      示例 3：
//          输入： nums = [2,2,2,4,4]
//          输出： true
//          解释：
//              数字 2 和 4 的频次都是质数。
//      提示：
//          1 <= nums.length <= 100
//          0 <= nums[i] <= 100

bool CheckPrimeFrequency(int *nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 10, n);
    PrintVecElement(vec, n);
    bool ans = CheckPrimeFrequency(vec, n);
    printf("数组中的元素频次是否存在为质数?\n");
    PrintBool(ans);
    FreeVec(vec);
}

bool JudgeIsPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    if (num % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(num); i+=2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 模拟：
// Time: O(N)
// Space: O(1)
bool CheckPrimeFrequency(int *nums, int numsSize)
{
    int arr[101] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
    }
    for (int i = 0; i <= 100; i++)
    {
        if (JudgeIsPrime(arr[i]) == true)
        {
            return true;
        }
    }
    return false;
}