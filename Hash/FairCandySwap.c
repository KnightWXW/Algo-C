#include "../Mybasic/mybasic.h"

//      LeetCode 888. 公平的糖果交换

//      链接：https://leetcode.cn/problems/fair-candy-swap/submissions/

//      爱丽丝和鲍勃拥有不同总数量的糖果。
//      给你两个数组 aliceSizes 和 bobSizes，
//      aliceSizes[i] 是爱丽丝拥有的第 i 盒糖果中的糖果数量，
//      bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。
//      两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。
//      一个人拥有的糖果总数量是他们每盒糖果数量的总和。
//      返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，
//      answer[1] 是鲍勃必须交换的糖果盒中的糖果的数目。
//      如果存在多个答案，你可以返回其中 任何一个。
//      题目测试用例保证存在与输入对应的答案。
//      示例 1：
//          输入：aliceSizes = [1,1], bobSizes = [2,2]
//          输出：[1,2]
//      示例 2：
//          输入：aliceSizes = [1,2], bobSizes = [2,3]
//          输出：[1,2]
//      示例 3：
//          输入：aliceSizes = [2], bobSizes = [1,3]
//          输出：[2,3]
//      示例 4：
//          输入：aliceSizes = [1,2,5], bobSizes = [2,4]
//          输出：[5,4]
//      提示：
//          1 <= aliceSizes.length, bobSizes.length <= 104
//          1 <= aliceSizes[i], bobSizes[j] <= 105
//          爱丽丝和鲍勃的糖果总数量不同。
//          题目数据保证对于给定的输入至少存在一个有效答案。

int *FairCandySwap(int *aliceSizes, int aliceSizesSize, int *bobSizes, int bobSizesSize, int *returnSize);

int main()
{
    int n1 = GenerateRandomNum(1, 20);
    int *aliceSizes = GenerateRandomVec(1, 100, n1);
    printf("Alice数组 元素为: \n");
    PrintVecElement(aliceSizes);
    int n2 = GenerateRandomNum(1, 21);
    int *bobSizes = GenerateRandomVec(1, 100, n2);
    printf("Bob数组 元素为: \n");
    PrintVecElement(bobSizes);
    int returnSize = 0;
    int *ans = FairCandySwap(aliceSizes, n1, bobSizes, n2, &returnSize);
    printf("ans数组 元素为：\n");
    PrintVecElement(ans, returnSize);
}

int *FairCandySwap(int *aliceSizes, int aliceSizesSize, int *bobSizes, int bobSizesSize, int *returnSize)
{
}
