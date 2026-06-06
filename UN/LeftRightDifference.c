#include "../Mybasic/mybasic.h"

//      LeetCode 2574. 左右元素和的差值

//      链接：https://leetcode-cn.com/problems/left-and-right-sum-differences/

//      给你一个下标从 0 开始的长度为 n 的整数数组 nums。
//      定义两个数组 leftSum 和 rightSum，其中：
//          leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
//          rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
//      返回长度为 n 数组 answer，其中 answer[i] = |leftSum[i] - rightSum[i]|。
//      示例 1：
//          输入：nums = [10,4,8,3]
//          输出：[15,1,11,22]
//          解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
//              数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
//      示例 2：
//          输入：nums = [1]
//          输出：[0]
//          解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
//              数组 answer 为 [|0 - 0|] = [0] 。
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 105

int* LeftRightDifference(int* nums, int numsSize, int* returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    PrintVecElement(vec, n);
    int returnSize = 0;
    int* ans_A = LeftRightDifference(vec, n, &returnSize);
    printf("左右元素和的差值 为\n");
    PrintVecElement(ans_A, n);
    FreeVec(vec);
    FreeVec(ans_A);
}

// 前缀和
// Time:O()
// Space:O()
int* LeftRightDifference(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
	int* ans = (int*)malloc(sizeof(int) * (numsSize));
    int* leftArr = (int*)malloc(sizeof(int) * (numsSize));
	int* rightArr = (int*)malloc(sizeof(int) * (numsSize));
	memset(ans, 0, sizeof(int) * (numsSize));
	memset(leftArr, 0, sizeof(int) * (numsSize));
	memset(rightArr, 0, sizeof(int) * (numsSize));
	leftArr[0] = nums[0];
	for(int i = 1; i < numsSize; i++)
	{
		leftArr[i] = leftArr[i - 1] + nums[i];
	}
	rightArr[numsSize - 1] = nums[numsSize - 1];
	for(int j = numsSize - 2; j >= 0; j--)
	{
		rightArr[j] = rightArr[j + 1] + nums[j];
	}
	for(int i = 0; i < numsSize; i++)
	{
		ans[i] = abs(leftArr[i] - rightArr[i]);
	}
	free(leftArr);
	free(rightArr);
	return ans;
}