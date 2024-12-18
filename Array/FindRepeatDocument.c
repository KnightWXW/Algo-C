#include "../Mybasic/mybasic.h"

//      LeetCode LCR 120. 寻找文件副本

//      链接：https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

//      设备中存有 n 个文件，文件 id 记于数组 documents。
//      若文件 id 相同，则定义为该文件存在副本。
//      请返回任一存在副本的文件 id。
//      示例 1：
//          输入：documents = [2, 5, 3, 0, 5, 0]
//          输出：0 或 5
//      提示：
//          0 ≤ documents[i] ≤ n-1
//          2 <= n <= 100000

void SwapElement(int *arr, int i, int j);
int FindRepeatDocument(int *documents, int documentsSize);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec = GenerateRandomVec(0, n - 1, n);
    PrintVecElement(vec, n);
    int ans = FindRepeatDocument(vec, n);
    printf("返回任一存在副本的文件 id 为: %d。\n", ans);
    FreeVec(vec);
}

void SwapElement(int *arr, int i, int j)
{
    int tem = arr[i];
    arr[i] = arr[j];
    arr[j] = tem;
    return;
}

// 原地交换(数组哈希):
// Time: O(N)
// Space: O(1)
int FindRepeatDocument(int *documents, int documentsSize)
{
    for (int i = 0; i < documentsSize; i++)
    {
        while (i != documents[i])
        {
            if (documents[i] == documents[documents[i]])
            {
                return documents[i];
            }
            SwapElement(documents, i, documents[i]);
        }
    }
    return -1;
}
