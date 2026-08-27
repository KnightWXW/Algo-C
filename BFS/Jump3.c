#include "../Mybasic/mybasic.h"

//      LeetCode 1306. 跳跃游戏 III

//      链接: https://leetcode.cn/problems/jump-game-iii/

//      给定一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。
//      当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。
//      请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。
//      注意，不管是什么情况下，你都无法跳到数组之外。
//      示例 1：
//          输入：arr = [4,2,3,0,3,1,2], start = 5
//          输出：true
//          解释：
//              到达值为 0 的下标 3 有以下可能方案：
//              下标 5 -> 下标 4 -> 下标 1 -> 下标 3
//              下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3
//      示例 2：
//          输入：arr = [4,2,3,0,3,1,2], start = 0
//          输出：true
//          解释：
//              到达值为 0 的下标 3 有以下可能方案：
//              下标 0 -> 下标 4 -> 下标 1 -> 下标 3
//      示例 3：
//          输入：arr = [3,0,2,1,2], start = 2
//          输出：false
//          解释：无法到达值为 0 的下标 1 处。
//      提示：
//          1 <= arr.length <= 5 * 104
//          0 <= arr[i] < arr.length
//          0 <= start < arr.length

bool Jump3_A(int *arr, int arrSize, int start);
bool Jump3_B(int *arr, int arrSize, int start);
bool Jump3_C(int *arr, int arrSize, int start);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int *vec1 = GenerateRandomVec(0, 10, n);
    int start = GenerateRandomNum(1, n - 1);
    PrintVecElement(vec1, n);
    int* vec2 = (int*)malloc(sizeof(int) * n);
    memcpy(vec2, vec1, sizeof(int) * n);
    int* vec3 = (int*)malloc(sizeof(int) * n);
    memcpy(vec3, vec1, sizeof(int) * n);
    bool ansA = Jump3_A(vec1, n, start);
    bool ansB = Jump3_B(vec2, n, start);
    bool ansC = Jump3_C(vec3, n, start);
    printf("(暴力递归)起始下标 为 %d, 能够跳到对应元素值为 0 的 任一 下标处？\n", start);
    PrintBool(ansA);
    printf("(记忆化搜索)起始下标 为 %d, 能够跳到对应元素值为 0 的 任一 下标处？\n", start);
    PrintBool(ansB);
    printf("(广度优先搜索)起始下标 为 %d, 能够跳到对应元素值为 0 的 任一 下标处？\n", start);
    PrintBool(ansC);
    FreeVec(vec1);
    FreeVec(vec2);
    FreeVec(vec3);
}

bool DFSJump3_A(int *arr, int arrSize, int i)
{
    if (arr[i] == 0)
    {
        return true;
    }
    else if (arr[i] < 0)
    {
        return false;
    }
    bool flag = false;
    int steps = arr[i];
    arr[i] = -steps;
    if (i - steps >= 0)
    {
        flag |= DFSJump3_A(arr, arrSize, i - steps);
    }
    if (i + steps < arrSize)
    {
        flag |= DFSJump3_A(arr, arrSize, i + steps);
    }
    return flag;
}

// 暴力递归
// Time: O(2^n)
// Space: O(n)
bool Jump3_A(int *arr, int arrSize, int start)
{
    return DFSJump3_A(arr, arrSize, start);
}

bool DFSJump3_B(int *arr, int arrSize, int i, int *mem)
{
    if (arr[i] == 0)
    {
        mem[i] = 1;
        return true;
    }
    if (arr[i] < 0)
    {
        return false;
    }
    if (mem[i] != -1)
    {
        return mem[i] == 1 ? true : false;
    }
    bool flag = false;
    int steps = arr[i];
    arr[i] = -steps;
    if (i - steps >= 0)
    {
        flag |= DFSJump3_B(arr, arrSize, i - steps, mem);
    }
    if (i + steps < arrSize)
    {
        flag |= DFSJump3_B(arr, arrSize, i + steps, mem);
    }
    mem[i] = flag == true ? 1 : 0;
    return flag;
}

bool Jump3_B(int *arr, int arrSize, int start)
{
    int *mem = (int *)malloc(sizeof(int) * arrSize);
    memset(mem, -1, sizeof(int) * arrSize);
    bool ans = DFSJump3_B(arr, arrSize, start, mem);
    free(mem);
    return ans;
}

// 广度优先搜索
// Time: O(N)
// Space: O(N)
bool Jump3_C(int *arr, int arrSize, int start)
{
    if (arr[start] == 0)
    {
        return true;
    }
    bool *vis = (bool *)malloc(sizeof(bool) * arrSize);
    memset(vis, 0, sizeof(bool) * arrSize);
    vis[start] = true;
    int *mem = (int *)malloc(sizeof(int) * arrSize);
    int front = 0;
    int rear = 0;
    mem[rear++] = start;
    while (front < rear)
    {
        int tem = mem[front++];
        int next[] = {tem - arr[tem], tem + arr[tem]};
        for (int i = 0; i < 2; i++)
        {
            int k = next[i];
            if (k >= 0 && k < arrSize && !vis[k])
            {
                if (arr[k] == 0)
                {
                    free(vis);
                    free(mem);
                    return true;
                }
                mem[rear++] = k;
                vis[k] = true;
            }
        }
    }
    free(vis);
    free(mem);
    return false;
}