#include "../Mybasic/mybasic.h"

//      Huawei：超大数序列

//      定义超大数序列：若数组的某个连续子序列中至少一个元素大于该子序列的平均数的num倍，
//      则称这一子序列为超大数序列。
//      给出一个整数数组cal, 请统计有多少个长度为size的超大数序列？
//      示例1：
//          输入： cal: [2, 3, 100, 3, 4, 6], size = 3, num = 2
//          输出：3
//      示例2：
//          输入： cal: [2, 3, 4, 3, 9, 12], size = 4, num = 2
//          输出：0

int MaxSubSequence(int *cal, int l, int size, int num);

int main()
{
    int cal1[] = {2, 3, 100, 3, 4, 6};
    int l1 = 6;
    int size1 = 3;
    int num1 = 2;
    int ans = MaxSubSequence(cal1, l1, size1, num1);
    PrintVecElement(cal1, l1);
    printf("num 为 %d, 有 %d 个长度为 %d 的超大数序列\n", num1, ans, size1);
}

// 滑动窗口：
// Time: O(N)
// Space: O(N)
int MaxSubSequence(int *cal, int l, int size, int num)
{
    int ans = 0;
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxEle = 0;
    while (left < l && right < l)
    {
        maxEle = max(maxEle, cal[right]);
        sum += cal[right];
        right++;
        if (right - left == size)
        {
            if (maxEle > sum * num / size)
            {
                ans++;
            }
            if (maxEle == cal[left])
            {
                left++;
                right = left;
                maxEle = 0;
                sum = 0;
            }
            else
            {
                sum -= cal[left];
                left++;
            }
        }
    }
    return ans;
}