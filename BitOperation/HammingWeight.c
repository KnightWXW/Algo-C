

//      LeetCode 191. 位1的个数

//      链接：https://leetcode.cn/problems/number-of-1-bits/

//      给定一个正整数 n，编写一个函数，
//      获取一个正整数的二进制形式并返回其二进制表达式中 设置位 的个数（也被称为汉明重量）。
//      示例 1：
//          输入：n = 11
//          输出：3
//          解释：输入的二进制串 1011 中，共有 3 个设置位。
//      示例 2：
//          输入：n = 128
//          输出：1
//          解释：输入的二进制串 10000000 中，共有 1 个设置位。
//      示例 3：
//          输入：n = 2147483645
//          输出：30
//          解释：输入的二进制串 1111111111111111111111111111101 中，共有 30 个设置位。
//      提示：
//          1 <= n <= 231 - 1

int HammingWeight_A(int n);

int main()
{
    int n = GenerateRandomNum(1, 10000);
    int ansA = HammingWeight_A(n);
    printf("数字 %d 位1 的个数为 %d.\n", n, ans_A);
}

// 位运算:
// Time: O(N)
// Space: O(1)
int HammingWeight_A(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int tem = n & 1;
        ans += tem == 1 ? 1 : 0;
        n >>= 1;
    }
    return ans;
}