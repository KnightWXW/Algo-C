#include "../Mybasic/mybasic.h"

//      Huawei: 虚拟机部署

//      虚拟化是云计算重要技术之一。一台物理机上部署一个或多个虚拟机,以优化资源的使用。
//      现有一批物理机记录与数组 capacities 中, capacities[i] 表示编号为 i 的物理机初始化内存大小；
//      同时给出一批虚拟机部署请求 requests, requests[i] 表示某虚拟机的所需内存。
//      请按照如下规则依次处理每个虚拟机部署请求，并返回每个虚拟机部署所在的物理机编号(或者 -1), 
//      如果所在物理机的可用内存都不足，则该虚拟机部署失败，结果为 -1。
//      否则，在满足虚拟机所需内存的所有物理机中，选择可用内存最小的；
//      若仍然有多台，则选择其中编号最小的。
//      样例1: 
//          输入：
//              [32, 256, 192, 64]
//              [128, 64, 64, 512]
//          输出：[2,2,3,-1]

int* VirtualMachineDeployment(int* capacities, int capacitiesSize, int* requests, int requestsSize);

