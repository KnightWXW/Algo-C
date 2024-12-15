#include "../Mybasic/mybasic.h"

//      LeetCode 1678. 设计 Goal 解析器

//      链接：https://leetcode.cn/problems/goal-parser-interpretation/

//      请你设计一个可以解释字符串 command 的 Goal 解析器 。
//      command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。
//      Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al"。
//      然后，按原顺序将经解释得到的字符串连接成一个字符串。
//      给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。
//      示例 1：
//          输入：command = "G()(al)"
//          输出："Goal"
//          解释：Goal 解析器解释命令的步骤如下所示：
//              G -> G
//              () -> o
//              (al) -> al
//              最后连接得到的结果是 "Goal"
//      示例 2：
//          输入：command = "G()()()()(al)"
//          输出："Gooooal"
//      示例 3：
//          输入：command = "(al)G(al)()()G"
//          输出："alGalooG"
//      提示：
//          1 <= command.length <= 100
//          command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成

char *GoalParserInterpretation(char *command);

int main()
{
    char s1[] = "G()(al)";
    PrintString(s1);
    bool ans1 = GoalParserInterpretation(s1);
    printf("Goal 解析器 的解释结果为: \n");
    FreeString(ans1);
    char s2[] = "G()()()()(al)";
    PrintString(s2);
    bool ans2 = GoalParserInterpretation(s2);
    printf("Goal 解析器 的解释结果为: \n");
    FreeString(ans2);
    char s3[] = "(al)G(al)()()G";
    PrintString(s3);
    bool ans3 = GoalParserInterpretation(s3);
    printf("Goal 解析器 的解释结果为: \n");
    FreeString(ans3);
}

// 字符串遍历:
// Space: O(N)
// Time: O(N)
char *GoalParserInterpretation(char *command)
{
    int l = strlen(command);
    char *ans = (char *)malloc(sizeof(char) * (l + 1));
    int index = 0;
    for (int i = 0; i < l; i++)
    {
        if (command[i] == 'G')
        {
            index += sprintf(ans + index, "%s", "G");
        }
        else if (command[i] == '(')
        {
            if (command[i + 1] == ')')
            {
                index += sprintf(ans + index, "%s", "o");
            }
            else
            {
                index += sprintf(ans + index, "%s", "al");
            }
        }
    }
    return ans;
}