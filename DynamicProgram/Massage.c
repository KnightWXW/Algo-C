#include "../Mybasic/mybasic.h"

//      LeetCode 面试题 17.16. 按摩师

//      链接: https://leetcode.cn/problems/the-masseuse-lcci/

//      一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
//      在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
//      给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
//      注意：本题相对原题稍作改动
//      示例 1：
//          输入： [1,2,3,1]
//          输出： 4
//          解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
//      示例 2：
//          输入： [2,7,9,3,1]
//          输出： 12
//          解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
//      示例 3：
//          输入： [2,1,4,5,3,1,1,3]
//          输出： 12
//          解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，
//              总时长 = 2 + 4 + 3 + 3 = 12。

int Massage_A(int* nums, int numsSize);
int Massage_B(int* nums, int numsSize);
int Massage_C(int* nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *nums = GenerateRandomVec(0, 20, n);
    PrintVecElement(nums, n);
    int ansA = Massage_A(nums, n);
    int ansB = Massage_B(nums, n);
    int ansC = Massage_C(nums, n);
    printf("暴力递归: 按摩师总预约时间最长 为 %d \n", ansA);
    printf("记忆化搜索: 按摩师总预约时间最长 为 %d \n", ansB);
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int Massage_A(int* nums, int numsSize)
{
    
}