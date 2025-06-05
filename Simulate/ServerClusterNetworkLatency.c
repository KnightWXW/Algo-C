#include "../Mybasic/mybasic.h"

//      Huawei: 服务器集群网络延迟

//      给定一个正整数数组表示某服务器集群内服务器的机位编号，
//      请选择一台服务器作为主服务器，使得集群网络延迟最小，并返回最小值。
//      每台服务器有唯一的机位编号;
//          两服务器之间的网络延迟，可以简单用所在机位编号之差的绝对差表示，服务器到自身的延迟为0;
//          集群网络延迟是指主服务器与所有服务器的网络延迟之和。
//      输入：
//          整数N, 数组元素个数, 元素取值范围 [1, 500]
//          N个整数，上述数组的元素 [1, 10000]
//      输出：
//          一个整数, 集群网络延迟的最小值
//      样例1：
//          输入1：
//              3
//              2 6 4
//          输出1：
//              4
//      样例2：
//          输入2：
//              4
//              2 4 3 1
//          输出2：
//              4

int DigitSumDiff(int k, int *arr, int l);
int ServerClusterNetworkLatency(int *arr, int l);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *vec = GenerateRandomVec(0, 100, n);
    PrintVecElement(vec, n);
    int ans_A = ServerClusterNetworkLatency(vec, n);
    printf("集群网络延迟最小 为 %d \n", ans_A);
}

int DigitSumDiff(int k, int *arr, int l)
{
    int sum = 0;
    int tem = 0;
    for (int i = 0; i < l; i++)
    {
        tem = abs(arr[i] - arr[k]);
        sum += tem;
    }
    return sum;
}

// 模拟：
// Time: O(N)
// Space: O(1)
int ServerClusterNetworkLatency(int *arr, int l)
{
    int ans = INT_MAX;
    int tem = 0;
    for (int i = 0; i < l; i++)
    {
        tem = DigitSumDiff(i, arr, l);
        ans = min(ans, tem);
    }
    return ans;
}