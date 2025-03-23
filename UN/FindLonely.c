

#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 2150. 找出数组中的所有孤独数字

//      链接：https://leetcode.cn/problems/find-all-lonely-numbers-in-the-array/

//      给你一个整数数组 nums 。如果数字 x 在数组中仅出现 一次 ，
//      且没有 相邻 数字（即，x + 1 和 x - 1）出现在数组中，则认为数字 x 是 孤独数字 。
//      返回 nums 中的 所有 孤独数字。你可以按 任何顺序 返回答案。
//      示例 1：
//          输入：nums = [10,6,5,8]
//          输出：[10,8]
//          解释：
//              - 10 是一个孤独数字，因为它只出现一次，并且 9 和 11 没有在 nums 中出现。
//              - 8 是一个孤独数字，因为它只出现一次，并且 7 和 9 没有在 nums 中出现。
//              - 5 不是一个孤独数字，因为 6 出现在 nums 中，反之亦然。
//              因此，nums 中的孤独数字是 [10, 8] 。
//              注意，也可以返回 [8, 10] 。
//      示例 2：
//          输入：nums = [1,3,5,3]
//          输出：[1,5]
//          解释：
//              - 1 是一个孤独数字，因为它只出现一次，并且 0 和 2 没有在 nums 中出现。
//              - 5 是一个孤独数字，因为它只出现一次，并且 4 和 6 没有在 nums 中出现。
//              - 3 不是一个孤独数字，因为它出现两次。
//              因此，nums 中的孤独数字是 [1, 5] 。
//              注意，也可以返回 [5, 1] 。
//      提示：
//          1 <= nums.length <= 105
//          0 <= nums[i] <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> FindLonely_A(vector<int> &nums);
vector<int> FindLonely_B(vector<int> &nums);
vector<int> FindLonely_C(vector<int> &nums);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, 30, n);
    printf("数组元素为：\n");
    PrintVecElement(vec);
    int returnA = 0;
    int *ans_A = FindLonely_A(vec, n, &returnA);
    printVecElement(ans_A, returnA);
    int returnB = 0;
    int *ans_B = FindLonely_B(vec, n, &returnB);
    printVecElement(ans_B, returnB);
    int returnC = 0;
    int *ans_C = FindLonely_C(vec, n, &returnC);
    printVecElement(ans_C, returnC);
    FreeVec(vec);
    FreeVec(ans_A);
    FreeVec(ans_B);
    FreeVec(ans_C);
}

// 哈希：
// Time: O(N)
// Space: O(N)
int *FindLonely_A(int *nums, int numsSize, int *returnSize)
{
}

// 排序1：
// Time: O(N)
// Space: O(N)
int *FindLonely_B(int *nums, int numsSize, int *returnSize)
{
}

// 排序2：
// Time: O(N)
// Space: O(N)
int *FindLonely_C(int *nums, int numsSize, int *returnSize)
{
}