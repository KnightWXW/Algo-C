#include "../Mybasic/mybasic.h"

//      LeetCode 1189. “气球” 的最大数量

//      链接: https://leetcode.cn/problems/maximum-number-of-balloons/

//      给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
//      字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
//      示例 1：
//          输入：text = "nlaebolko"
//          输出：1
//      示例 2：
//          输入：text = "loonbalxballpoon"
//          输出：2
//      示例 3：
//          输入：text = "leetcode"
//          输出：0
//      提示：
//          1 <= text.length <= 104
//          text 全部由小写英文字母组成

int MaxNumberOfBalloons(char *text);

int main()
{
    int n = GenerateRandomNum(1, 30);
    char arr1[] = {'b', 'a', 'l', 'l', 'o', 'o', 'n', 'c', 'd', 'e'};
    int len = (int)(sizeof(arr1) / sizeof(arr1[0]));
    char *s = GenerateRandomString(n, arr1, len);
    PrintString(s);
    int ans_A = MaxNumberOfBalloons(s);
    printf("气球 的最大数量为：%d\n", ans_A);
    FreeString(s);
}

// 单向遍历 + 数组哈希:
// Time: O(N)
// Space: O(1)
int MaxNumberOfBalloons(char *text)
{
    int l = strlen(text);
    int vec[5] = {0};
    int ans = l;
    for (int i = 0; i < l; i++)
    {
        char c = text[i];
        switch (c)
        {
        case 'b':
            vec[0]++;
            break;
        case 'a':
            vec[1]++;
            break;
        case 'l':
            vec[2]++;
            break;
        case 'o':
            vec[3]++;
            break;
        case 'n':
            vec[4]++;
            break;
        default:
            break;
        }
    }
    vec[2] >>= 1;
    vec[3] >>= 1;
    for (int i = 0; i < 5; i++)
    {
        ans = min(vec[i], ans);
    }
    return ans;
}
