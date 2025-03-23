


#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>     

using namespace std;

//      LeetCode 14. 最长公共前缀

//      链接：https://leetcode.cn/problems/longest-common-prefix/

//      编写一个函数来查找字符串数组中的最长公共前缀。
//      如果不存在公共前缀，返回空字符串 ""。
//      示例 1：
//          输入：strs = ["flower","flow","flight"]
//          输出："fl"
//      示例 2：
//          输入：strs = ["dog","racecar","car"]
//          输出：""
//          解释：输入不存在公共前缀。
//      提示：
//          1 <= strs.length <= 200
//          0 <= strs[i].length <= 200
//          strs[i] 仅由小写英文字母组成

char* LongestCommonPrefix_A(char** strs);
char* LongestCommonPrefix_B(char** strs);

int main()
{
    int n = generateRandomNum(2, 4);
    char arr1[] = {'A', 'L', 'P'};
    char** strs = GenerateRandomString(n, 1, 10);
    printStringVector(strs);
    char* ans_A = LongestCommonPrefix_A(strs);
    char* ans_B = LongestCommonPrefix_B(strs);
    printf("字符串数组中的最长公共前缀为：\n");
    PrintString(ans_A);
    PrintString(ans_B);
}


// 纵向比较：
// Time: O(N * M)
// Space: O(1)
char* LongestCommonPrefix_A(char** strs)
{
    char cur = ' ';
    for (int j = 0; j < strs[0].size(); j++)
    {
        cur = strs[0][j];
        for (int i = 1; i < strs.size(); i++)
        {
            if (j >= strs[i].size() || strs[i][j] != cur)
            {
                return strs[0].substr(0, j);
            }
        }
    }
    return strs[0];
}

// 横向比较：
// Time: O(N * M)
// Space: O(1)
string LongestCommonPrefix_B(vector<string> &strs)
{
    int l = strs.size();
    if (l == 0)
    {
        return "";
    }
    string cur = strs[0];
    int ans = INT_MAX;
    for(int i = 0; i < l; i++){
        int index = 0;
        while(index < strs[i].size() && index < cur.size()){
            if(strs[i][index] != cur[index]){
                break;
            }
            index++;
        }
        ans = min(ans, index);
        if(ans == 0){
            return "";
        }
    }
    return strs[0].substr(0, ans);
}