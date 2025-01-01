#include "../Mybasic/mybasic.h"

//      LeetCode 379 电话目录管理系统

//      链接：https://leetcode-cn.com/problems/design-phone-directory/

//      设计一个电话目录管理系统，让它支持以下功能：
//          int get(): 分配给用户一个未被使用的电话号码，获取失败请返回 -1
//          bool check(int number): 检查指定的电话号码是否被使用
//          void release(int number): 释放掉一个电话号码，使其能够重新被分配
//      示例
//          PhoneDirectory directory = new PhoneDirectory(3);
//          // 初始化电话目录，包括 3 个电话号码：0，1 和 2。
//          directory.get();// 可以返回任意未分配的号码，这里我们假设它返回 0。
//          directory.get();// 假设，函数返回 1。
//          directory.check(2);// 号码 2 未分配，所以返回为 true。
//          directory.get();// 返回 2，分配后，只剩一个号码未被分配。
//          directory.check(2);// 此时，号码 2 已经被分配，所以返回 false。
//          directory.release(2);// 释放号码 2，将该号码变回未分配状态。
//          directory.check(2);// 号码 2 现在是未分配状态，所以返回 true。

typedef struct
{
    int *flag;
    int size;
} PhoneDirectorySystem;

PhoneDirectorySystem *PhoneDirectorySystemCreate(int maxNumbers)
{
    PhoneDirectorySystem *obj = (PhoneDirectorySystem *)malloc(sizeof(PhoneDirectorySystem));
    obj->flag = (int *)malloc(sizeof(int) * maxNumbers);
    obj->size = maxNumbers;
    memset(obj->flag, 0, sizeof(int) * maxNumbers);
    return obj;
}

int PhoneDirectorySystemGet(PhoneDirectorySystem **obj)
{
    for (int i = 0; i < (*obj)->size; i++)
    {
        if ((*obj)->flag[i] == 0)
        {
            (*obj)->flag[i] = 1;
            return i;
        }
    }
    return -1;
}

bool PhoneDirectorySystemCheck(PhoneDirectorySystem *obj, int number)
{
    return (obj)->flag[number] == 0;
}

void PhoneDirectorySystemRelease(PhoneDirectorySystem **obj, int number)
{
    (*obj)->flag[number] = 0;
}

void PhoneDirectorySystemFree(PhoneDirectorySystem *obj)
{
    free(obj->flag);
    free(obj);
}

int main()
{
    PhoneDirectorySystem *phoneDirectorySystem = PhoneDirectorySystemCreate(3);
    int g1 = PhoneDirectorySystemGet(&phoneDirectorySystem);
    printf("获取结果 为: %d\n", g1); // 0
    int g2 = PhoneDirectorySystemGet(&phoneDirectorySystem);
    printf("获取结果 为: %d\n", g2); // 1
    bool c1 = PhoneDirectorySystemCheck(phoneDirectorySystem, 2);
    printf("检查结果 为:\n");
    PrintBool(c1); // true
    int g3 = PhoneDirectorySystemGet(&phoneDirectorySystem);
    printf("获取结果 为: %d\n", g3); // 2
    bool c2 = PhoneDirectorySystemCheck(phoneDirectorySystem, 2);
    printf("检查结果 为:\n");
    PrintBool(c2); // false
    PhoneDirectorySystemRelease(&phoneDirectorySystem, 2);
    bool c3 = PhoneDirectorySystemCheck(phoneDirectorySystem, 2);
    printf("检查结果 为:\n");
    PrintBool(c3); // true
    PhoneDirectorySystemFree(phoneDirectorySystem);
}