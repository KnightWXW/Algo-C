#include "../Mybasic/mybasic.h"

//      LeetCode 187. 重复的DNA序列

//      链接：https://leetcode.cn/problems/repeated-dna-sequences/

//      DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
//      例如，"ACGAATTCCG" 是一个 DNA序列 。
//      在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//      给定一个表示 DNA序列 的字符串 s ，
//      返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。
//      你可以按 任意顺序 返回答案。
//      示例 1：
//          输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//          输出：["AAAAACCCCC","CCCCCAAAAA"]
//      示例 2：
//          输入：s = "AAAAAAAAAAAAA"
//          输出：["AAAAAAAAAA"]
//      提示：
//          0 <= s.length <= 105
//          s[i]=='A'、'C'、'G' or 'T'

char **FindRepeatedDnaSequences(char *s, int *returnSize);

int main()
{
    char *s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    printf("DNA序列为:\n");
    PrintString(s1);
    int rs1 = 0;
    char **ans1 = FindRepeatedDnaSequences(s1, &rs1);
    printf("重复的DNA序列 为:\n");
    PrintStringVec(ans1, rs1);
    FreeStringVec(ans1, rs1);

    char *s2 = "AAAAAAAAAAAAA";
    printf("DNA序列为:\n");
    PrintString(s2);
    int rs2 = 0;
    char *ans2 = ConvertDateToBinary(s2, &rs2);
    printf("重复的DNA序列 为:\n");
    PrintString(ans2, rs2);
    FreeString(ans2, rs2);
}

char **FindRepeatedDnaSequences(char *s, int *returnSize)
{
}