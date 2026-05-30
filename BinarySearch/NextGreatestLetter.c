#include "../Mybasic/mybasic.h"

//      LeetCode 744. 寻找比目标字母大的最小字母

//      链接: https://leetcode.cn/problems/find-smallest-letter-greater-than-target/

//      给你一个字符数组 letters，该数组按 非递减顺序 排序，
//      以及一个字符 target。letters 里至少有两个不同的字符。
//      返回 letters 中大于 target 的最小的字符。
//      如果不存在这样的字符，则返回 letters 的第一个字符。
//      示例 1：
//          输入: letters = ['c', 'f', 'j'], target = 'a'
//          输出: 'c'
//          解释：letters 中字典上比 'a' 大的最小字符是 'c'。
//      示例 2:
//          输入: letters = ['c','f','j'], target = 'c'
//          输出: 'f'
//          解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
//      示例 3:
//          输入: letters = ['x','x','y','y'], target = 'z'
//          输出: 'x'
//          解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
//      提示：
//          2 <= letters.length <= 104
//          letters[i] 是一个小写字母
//          letters 按非递减顺序排序
//          letters 最少包含两个不同的字母
//          target 是一个小写字母

char NextGreatestLetter_A(char *letters, int lettersSize, char target);
char NextGreatestLetter_B(char *letters, int lettersSize, char target);

int main()
{
    char arr1[4] = {'c', 'f', 'j'};
    char t1 = 'a';
    char ans1A = NextGreatestLetter_A(arr1, strlen(arr1), t1);
    char ans1B = NextGreatestLetter_B(arr1, strlen(arr1), t1);
    PrintString(arr1);
    printf("比目标字母 %c 大的最小字母 %c\n", t1, ans1A);
    printf("比目标字母 %c 大的最小字母 %c\n", t1, ans1B);

    char arr2[5] = {'x', 'x', 'y', 'y'};
    char t2 = 'z';
    char ans2A = NextGreatestLetter_A(arr2, strlen(arr2), t2);
    char ans2B = NextGreatestLetter_B(arr2, strlen(arr2), t2);
    PrintString(arr2);
    printf("比目标字母 %c 大的最小字母 %c\n", t2, ans2A);
    printf("比目标字母 %c 大的最小字母 %c\n", t2, ans2B);
}

// 线性查找:
// Time：O(N)
// Space: O(1)
char NextGreatestLetter_A(char *letters, int lettersSize, char target)
{
    int p = 26;
    char ans = ' ';
    for (int i = 0; i < lettersSize; i++)
    {
        if (letters[i] - target > 0 && letters[i] - target < p)
        {
            p = letters[i] - target;
            ans = letters[i];
        }
    }
    if (p == 26)
    {
        return letters[0];
    }
    return ans;
}

// 二分查找:
// Time: O(NlogN)
// Space: O(logN)
char NextGreatestLetter_B(char *letters, int lettersSize, char target)
{
    int left = 0;
    int right = lettersSize - 1;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (letters[mid] > target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return letters[ans];
}