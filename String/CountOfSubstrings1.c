#include "../Mybasic/mybasic.h"

//      LeetCode 3305. 元音辅音字符串计数 I

//      链接：https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/

//      给你一个字符串 word 和一个 非负 整数 k。

//      返回 word 的 子字符串 中，每个元音字母（'a'、'e'、'i'、'o'、'u'）至少 出现一次，
//      并且 恰好 包含 k 个辅音字母的子字符串的总数。
//      示例 1：
//          输入：word = "aeioqq", k = 1
//          输出：0
//          解释：
//              不存在包含所有元音字母的子字符串。
//       示例 2：
//          输入：word = "aeiou", k = 0
//          输出：1
//          解释：
//               唯一一个包含所有元音字母且不含辅音字母的子字符串是 word[0..4]，即 "aeiou"。
//       示例 3：
//          输入：word = "ieaouqqieaouqq", k = 1
//          输出：3
//          解释：
//              包含所有元音字母并且恰好含有一个辅音字母的子字符串有：
//                  word[0..5]，即 "ieaouq"。
//                  word[6..11]，即 "qieaou"。
//                  word[7..12]，即 "ieaouq"。
//        提示：
//           5 <= word.length <= 250
//           word 仅由小写英文字母组成。
//           0 <= k <= word.length - 5

int CountOfSubstrings1(char* word, int k);

int main()
{
    int n = GenerateRandomNum(5, 20);
    int k = GenerateRandomNum(0, n - 5);
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *str = GenerateRandomString(n, arr, strlen(str) + 1);
    PrintString(str);
    printf("word 为：\n");
    int ans_A = CountOfSubstrings1(str, k);
    printf(" 恰好 包含 %d 个辅音字母的子字符串的总数为 %d \n", k, ans_A);
    FreeString(str);
}


// 滑动窗口
// Time: O(N)
// Space: O(1)
int CountOfSubstrings1(char* word, int k)
{
    int l = strlen(word);
    int ans = 0;
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    for(
        
    )
}
