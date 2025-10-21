#include "../Mybasic/mybasic.h"

//      Huawei: 互斥任务规划

//      任务列表 task 有 N 个任务，任务编号 Ni 范围为 [0, N - 1]
//      由于存在资源竞争，某些任务之间有两两互斥关系，
//      并记录在二维数组 mutexPairs 中，
//      该二维数组元素为 [Ni, Nj] ，其中 Ni，Nj 为互斥的两个任务编号
//      现在需要对任务列表 task 进行切割分组，要求
//          存在互斥关系的任务不能分在一组
//          单个任务也可以单独一组
//          一个任务可以与多个任务互斥
//      请判断至少 可以将 任务列表 tasks 切割为多少组 ？
//      (切割后的小组为原数组的连续子数组)
//      示例 1：
//          输入：tasks = {1,3,2,4,6,5,0}
//                mutexPairs = {{1,3}, {4,5}}
//          输出：3
//      示例 2：
//          输入：tasks = {0,1,2,3,4,5}
//                mutexPairs = {{1,3}, {3,5}}
//          输出：3

int MutuallyTaskPlan(vector<int> tasks, vector<vector<int>> mutexPairs);

int main()
{
    int l1 = 7;
    int tasks1[] = {1, 3, 2, 4, 6, 5, 0};
    vector<vector<int>> mutexPairs1 = {{1, 3}, {4, 5}};
    int ans1 = MutuallyTaskPlan(tasks1, mutexPairs1);
    printVec(tasks1);
    print2DVecElement(mutexPairs1);
    printf("至少 可以将 任务列表 tasks 切割为 %d 组 \n", ans1); // 3

    vector<int> tasks2 = {0, 1, 2, 3, 4, 5};
    vector<vector<int>> mutexPairs2 = {{1, 3}, {3, 5}};
    int ans2 = MutuallyTaskPlan(tasks2, mutexPairs2);
    printVec(tasks2);
    print2DVecElement(mutexPairs2);
    printf("至少 可以将 任务列表 tasks 切割为 %d 组 \n", ans2); // 3
}

int MutuallyTaskPlan(vector<int> tasks, vector<vector<int>> mutexPairs)
{
    
}