#include "../Mybasic/mybasic.h"

//      LeetCode LCR 182. 动态口令

//      链接：https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

//      某公司门禁密码使用动态口令技术。初始密码为字符串 password，密码更新均遵循以下步骤：
//      设定一个正整数目标值 target
//      将 password 前 target 个字符按原顺序移动至字符串末尾
//      请返回更新后的密码字符串。
//      示例 1：
//          输入: password = "s3cur1tyC0d3", target = 4
//          输出: "r1tyC0d3s3cu"
//      示例 2：
//          输入: password = "lrloseumgh", target = 6
//          输出: "umghlrlose"
//      提示：
//          1 <= target < password.length <= 10000

char *DynamicPassword(char *password, int target);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int target = GenerateRandomNum(0, n / 2 + 1);
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *str = GenerateRandomString(n, arr, strlen(str));
    PrintString(str);
    char *ans_A = DynamicPassword(str, target);
    printf("更新 %d 个字符后的密码字符串为：\n", target);
    PrintString(ans_A);
    FreeString(str);
    FreeString(ans_A);
}

// 函数使用：
//      char *strncpy(char *dest, const char *src, size_t n);
//      dest: 目标字符串的指针, src: 源字符串的指针, n: 要复制的字符数
// Time: O(1)
// Space: O(N)
char *DynamicPassword(char *password, int target)
{
    int l = strlen(password);
    char *ans = (char *)malloc(sizeof(char) * (l + 1));
    memset(ans, 0, sizeof(char) * (l + 1));
    strncpy(ans, password + target, l - target);
    strncpy(ans + l - target, password, target);
    return ans;
}
