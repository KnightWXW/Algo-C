#include "../Mybasic/mybasic.h"

//      LeetCode 412. Fizz Buzz

//      链接：https://leetcode.cn/problems/fizz-buzz/

//      给你一个整数 n ，返回一个字符串数组 answer（下标从 1 开始），其中：
//          answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
//          answer[i] == "Fizz" 如果 i 是 3 的倍数。
//          answer[i] == "Buzz" 如果 i 是 5 的倍数。
//          answer[i] == i （以字符串形式）如果上述条件全不满足。
//      示例 1：
//          输入：n = 3
//          输出：["1","2","Fizz"]
//      示例 2：
//          输入：n = 5
//          输出：["1","2","Fizz","4","Buzz"]
//      示例 3：
//          输入：n = 15
//          输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
//      提示：
//          1 <= n <= 104

#define FIZZBUZZ_LEN 10

char **FizzBuzz(int n, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 30);
    int returnSize = 0;
    char **ans = FizzBuzz(n, &returnSize);
    printf(" %d 的 FizzBuzz数组 为:\n", n);
    PrintStringVec(ans, returnSize);
    FreeStringVec(ans, returnSize);
}

char **FizzBuzz(int n, int *returnSize)
{
    char **ans = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = (char *)malloc(sizeof(char) * FIZZBUZZ_LEN);
        memset(ans[i], 0, sizeof(char) * FIZZBUZZ_LEN);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 5 == 0 && i % 3 == 0)
        {
            strcpy(ans[i - 1], "FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            strcpy(ans[i - 1], "Fizz");
        }
        else if (i % 5 == 0)
        {
            strcpy(ans[i - 1], "Buzz");
        }
        else
        {
            sprintf(ans[i - 1], "%d", i);
        }
    }
    *returnSize = n;
    return ans;
}