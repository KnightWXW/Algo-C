#include "../Mybasic/mybasic.h"

//      Huawei: 最长空闲内存

//      某系统中有一空间连续的内存，被划分为多个大小相同的内存块
//      内存的使用状态记录在字符串memeory中，每个内存块的状态用字符X或者.表示，其中：
//          .   表示该内存块空闲
//          X   表示该内存块被使用
//      现在最多可释放cnt个内存块(字符串的X变为.)来获得空间连续的内存，
//      求可以获得的最长空闲的连续内存块数量
//      示例1：
//          输入：memory = "..X..X..XX..."  cnt = 2
//          输出：8
//      示例2：
//          输入：memory = "....X."  cnt = 3
//          输出：6
//      示例3：
//          输入：memory = "XX.X..XX....X..."  cnt = 0
//          输出：4
//      提示：0 <= cnt <= memory.size() <= 10^5

int MaximumIdleMemory(char *s, int cnt);

int main()
{
    int n = GenerateRandomNum(0, 100);
    int cnt = GenerateRandomNum(0, n);
    char arr[] = {'.', 'X'};
    char *s = GenerateRandomString(n, arr, 2);
    PrintString(s);
    int ans = MaximumIdleMemory(s, cnt);
    printf("最多可释放 %d 个内存块, \n可以获得的最长空闲的连续内存块块数量为 %d\n", cnt, ans);
}

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int MaximumIdleMemory(char *s, int cnt)
{
    
}