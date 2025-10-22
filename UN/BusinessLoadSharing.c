#include "../Mybasic/mybasic.h"

//      Huawei: 业务负载分担

//      现在有一个服务器集群(服务器数量为 serveNum),
//      和一批不同类型的任务(用数组 task 表示，下标表示任务类型，值表示任务数量)；
//      现需要把这批任务都分配到集群的服务器上，分配规则如下：
//      应业务安全要求，不同类型的任务不能分配到同一台服务器上，
//      一种类型的多个任务可以分配在多台服务器上
//      “负载”定义为某台服务器所分配的任务个数，无任务的服务器负载为0
//      “最高负载”定义为所有服务器中负载的最大值
//      请你制定分配方案，使得分配后 “最高负载” 的值最小，并返回该最小值。
//      输入：
//          集群中服务器的数量
//          这批任务有 taskTypeNum 种类型
//          taskTypeNum个整数，为task数组，表示这批任务
//      输出：
//          “最高负载” 的最小值
//      示例1：
//          输入：
//              5
//              2
//              7 4
//          输出:
//              3
//      示例2：
//          输入：
//              8
//              5
//              101 1 1 20 40
//          输出:
//              34

int BusinessLoadSharing(int* arr, int n, int serveNum);

int main()
{
    int n = GenerateRandomNum(0, 30);
    int* vec = GenerateRandomVec(0, 100, n);
    int serveNum = GenerateRandomNum(0, 50);
    PrintVecElement(vec, n);
    int ans_A = BusinessLoadSharing(vec, n, serveNum);
    printf("当服务器数量为 %d 时, 分配后 “最高负载” 的值最小为 %d\n", serveNum, ans_A);
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int BusinessLoadSharing(int* arr, int n, int serveNum)
{
    
}