#include "../Mybasic/mybasic.h"

//      LeetCode 2645. 构造有效字符串的最少插入数

//      链接：https://leetcode.cn/problems/minimum-additions-to-make-valid-string/

//      给你一个字符串 word ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，
//      返回使 word 有效 需要插入的最少字母数。
//      如果字符串可以由 "abc" 串联多次得到，则认为该字符串 有效 。
//      示例 1：
//          输入：word = "b"
//          输出：2
//          解释：在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "abc" 。
//      示例 2：
//          输入：word = "aaa"
//          输出：6
//          解释：在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "abcabcabc" 。
//      示例 3：
//          输入：word = "abc"
//          输出：0
//          解释：word 已经是有效字符串，不需要进行修改。
//      提示：
//          1 <= word.length <= 50
//          word 仅由字母 "a"、"b" 和 "c" 组成。

int AddMinimum(char* word);

int main()
{
    int n = GenerateRandomNum(1, 20);
    char* str = GenerateRandomString(n);
    printString(str);
    int ans_A = AddMinimum(str);
    printf("使 word 有效 需要插入的最少字母数：%d\n", ans_A);
    FreeString(str);
}

// 贪心：
// Time: O(N)
// Space: O(1)
int AddMinimum(char* word)
{
    
}