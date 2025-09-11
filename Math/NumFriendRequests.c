#include "../Mybasic/mybasic.h"

//      LeetCode 825. 适龄的朋友

//      链接: https://leetcode.cn/problems/friends-of-appropriate-ages/

//      在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。
//      如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：
//          ages[y] <= 0.5 * ages[x] + 7
//          ages[y] > ages[x]
//          ages[y] > 100 && ages[x] < 100
//      否则，x 将会向 y 发送一条好友请求。
//      注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。
//      另外，用户不会向自己发送好友请求。
//      返回在该社交媒体网站上产生的好友请求总数。
//      示例 1：
//          输入：ages = [16,16]
//          输出：2
//          解释：2 人互发好友请求。
//      示例 2：
//          输入：ages = [16,17,18]
//          输出：2
//          解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
//      示例 3：
//          输入：ages = [20,30,100,110,120]
//          输出：3
//          解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
//      提示：
//          n == ages.length
//          1 <= n <= 2 * 104
//          1 <= ages[i] <= 120

int NumFriendRequests(int* ages, int agesSize);

int main()
{
    int n = GenerateRandomNum(1, 100);
    int *arr = GenerateRandomVec(1, 100, n);
    printf("arr数组 元素为: ");
    PrintVecElement(arr, n);
    int ans_A = NumFriendRequests(arr, n);
    printf("全部为 0 的 子数组 数目: %d\n", ans_A);
    FreeVec(arr);
}

// 数学:
// Time：O(1)
// Space：O(1)
int NumFriendRequests(int* ages, int agesSize)
{

}
