#include "../Mybasic/mybasic.h"

//      LeetCode 46. 全排列

//      链接：https://leetcode.cn/problems/permutations/

//      给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列。
//      你可以 按任意顺序 返回答案。
//      示例 1：
//          输入：nums = [1,2,3]
//          输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//      示例 2：
//          输入：nums = [0,1]
//          输出：[[0,1],[1,0]]
//      示例 3：
//          输入：nums = [1]
//          输出：[[1]]
//      提示：
//          1 <= nums.length <= 6
//          -10 <= nums[i] <= 10
//          nums 中的所有整数 互不相同

int **Permute_A(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);

int **Permute_B(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);

int main()
{
    int n = GenerateRandomNum(0, 5);
    int* vec = GenerateRandomVec(0, 9, n);
    int row = 0;
    int** col = NULL;
    int** ans_A = Permute_A(vec, n, &row, col);
    printf("vec数组 元素为:");
    PrintVecElement(vec, n);
}

int **Permute_A(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
}