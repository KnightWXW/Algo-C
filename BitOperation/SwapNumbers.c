#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 16.01. 交换数字

//      链接：https://leetcode.cn/problems/swap-numbers-lcci/

//      编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
//      示例：
//          输入: numbers = [1,2]
//          输出: [2,1]
//      提示：
//          numbers.length == 2
//          -2147483647 <= numbers[i] <= 2147483647

int* SwapNumbers(int* numbers, int numbersSize, int* returnSize);

int main()
{
    int n = 2;
    int* vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int rs = 0;
    int* ans = SwapNumbers(vec, n, &rs);
    printf("交换数字后数组为：\n");
    PrintVecElement(ans, rs);
}

// 位运算：
// Time: O(N)
// Space: O(1)
int* SwapNumbers(int* numbers, int numbersSize, int* returnSize)
{
    * returnSize = numbersSize;
    numbers[0] ^= numbers[1];
    numbers[1] ^= numbers[0];
    numbers[0] ^= numbers[1];
    return numbers;
}