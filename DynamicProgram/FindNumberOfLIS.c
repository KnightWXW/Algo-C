
//      LeetCode 673. 最长递增子序列的个数

//      链接: https://leetcode.cn/problems/number-of-longest-increasing-subsequence/

//      给定一个未排序的整数数组 nums，返回最长递增子序列的个数 。
//      注意 这个数列必须是 严格 递增的。
//      示例 1:
//          输入: [1,3,5,4,7]
//          输出: 2
//          解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
//      示例 2:
//          输入: [2,2,2,2,2]
//          输出: 5
//          解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
//      提示: 
//          1 <= nums.length <= 2000
//          -106 <= nums[i] <= 106

int FindNumberOfLIS_A(int* nums, int numsSize);

int main()
{
    int n = GenerateRandomNum(1, 10);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ansA = FindNumberOfLIS_A(vec, n);
    int ansB = FindNumberOfLIS_B(vec, n);
    int ansC = FindNumberOfLIS_C(vec, n);
    printf("暴力递归: 最长递增子序列的个数 为 %d\n", ansA);
    printf("记忆化搜索: 最长递增子序列的个数 为 %d\n", ansB);
    printf("动态规划: 最长递增子序列的个数 为 %d\n", ansC);
    FreeVec(vec);
}