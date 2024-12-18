#include "../Mybasic/mybasic.h"

//      LeetCode 1299. 将每个元素替换为右侧最大元素

//      链接：https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/

//      给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，
//      如果是最后一个元素，用 -1 替换。
//      完成所有替换操作后，请你返回这个数组。
//      示例 1：
//          输入：arr = [17,18,5,4,6,1]
//          输出：[18,6,6,6,1,-1]
//      解释：
//          - 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
//          - 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
//          - 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
//          - 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
//      示例 2：
//          输入：arr = [400]
//          输出：[-1]
//          解释：下标 0 的元素右侧没有其他元素。
//      提示：
//          1 <= arr.length <= 104
//          1 <= arr[i] <= 105

int *ReplaceElements(int *arr, int arrSize, int *returnSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(1, 100, n);
    int returnSize = n;
    PrintVecElement(vec, n);
    int *ans = ReplaceElements(vec, n, &returnSize);
    printf("每个元素用它右边最大的元素替换后，数组为:\n");
    PrintVecElement(ans, returnSize);
    FreeVec(vec);
    FreeVec(ans);
}

int *ReplaceElements(int *arr, int arrSize, int *returnSize)
{
    *returnSize = arrSize;
    int *ans = (int *)malloc(*returnSize * sizeof(int));
    memset(ans, 0, sizeof(*ans));
    ans[*returnSize - 1] = -1;
    int maxVal = arr[arrSize - 1];
    for (int i = *returnSize - 2; i >= 0; i--)
    {
        if (maxVal < arr[i + 1])
        {
            maxVal = arr[i + 1];
        }
        ans[i] = maxVal;
    }
    return ans;
}