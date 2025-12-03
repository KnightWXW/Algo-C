#include "../Mybasic/mybasic.h"

//      LeetCode 139. 单词拆分

//      链接：https://leetcode.cn/problems/word-break/

//      给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
//      如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//      注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//      示例 1：
//          输入: s = "leetcode", wordDict = ["leet", "code"]
//          输出: true
//          解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//      示例 2：
//          输入: s = "applepenapple", wordDict = ["apple", "pen"]
//          输出: true
//          解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//              注意，你可以重复使用字典中的单词。
//      示例 3：
//          输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//          输出: false
//      提示：
//          1 <= s.length <= 300
//          1 <= wordDict.length <= 1000
//          1 <= wordDict[i].length <= 20
//          s 和 wordDict[i] 仅由小写英文字母组成
//          wordDict 中的所有字符串 互不相同

bool WordBreak_A(char *s, char **wordDict, int wordDictSize);
bool WordBreak_B(char *s, char **wordDict, int wordDictSize);
bool WordBreak_C(char *s, char **wordDict, int wordDictSize);

int main()
{
    char s1[] = "leetcode";
    char* arr1[] = {"leet", "code"};
    int n1 = 2;
    bool bA1 = WordBreak_A(s1, arr1, n1);
    bool bB1 = WordBreak_B(s1, arr1, n1);
    bool bC1 = WordBreak_C(s1, arr1, n1);
    printf("暴力递归: 单词拆分 结果 为 \n");
    PrintBool(bA1);
    printf("记忆化搜索: 单词拆分 结果 为 \n");
    PrintBool(bB1);
    printf("动态规划: 单词拆分 结果 为 \n");
    PrintBool(bC1);

    char s2[] = "applepenapple";
    char* arr2[] = {"apple", "pen"};
    int n2 = 2;
    bool bA2 = WordBreak_A(s2, arr2, n2);
    bool bB2 = WordBreak_B(s2, arr2, n2);
    bool bC2 = WordBreak_C(s2, arr2, n2);
    printf("暴力递归: 单词拆分 结果 为 \n");
    PrintBool(bA2);
    printf("记忆化搜索: 单词拆分 结果 为 \n");
    PrintBool(bB2);
    printf("动态规划: 单词拆分 结果 为 \n");
    PrintBool(bC2);

    char s3[] = "catsandog";
    char* arr3[] = {"cats", "dog", "sand", "and", "cat"};
    int n3 = 2;
    bool bA3 = WordBreak_A(s3, arr3, n3);
    bool bB3 = WordBreak_B(s3, arr3, n3);
    bool bC3 = WordBreak_C(s3, arr3, n3);
    printf("暴力递归: 单词拆分 结果 为 \n");
    PrintBool(bA3);
    printf("记忆化搜索: 单词拆分 结果 为 \n");
    PrintBool(bB3);
    printf("动态规划: 单词拆分 结果 为 \n");
    PrintBool(bC3);
}

bool WordBreak_A(char *s, char **wordDict, int wordDictSize)
{
    
}