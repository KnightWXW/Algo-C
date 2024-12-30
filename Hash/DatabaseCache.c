#include "../Mybasic/mybasic.h"

//      Huawei: 数据库缓存

//      缓存是一种提高数据库查询效率的手段，试用训练数据进行模拟访问，以对缓存机制进行优化。
//      模拟访问规则如下：
//          当查询的数据在缓存中时，直接访问缓存，无需访问数据库；
//          当查询的数据不在缓存中，则需要访问数据库，并把数据放入缓存；
//          若放入前回缓存已满，则必须先删除缓存中的一个数据；
//      给定缓存大小的训练数据(一组数据编号)，依次模拟访问这组数据，
//      请分析在访问规则下最少的数据库访问次数。

int DatabaseCache(int* data, int cache);

int main()
{
    int n = GenerateRandomNum(1, 20);
    int cache = GenerateRandomNum(1, 10);
    int* vec = GenerateRandomVec(1, 10, n);
    PrintVecElement(vec);
    int ans_A = DatabaseCache(vec, cache);
    printf("缓存大小为 %d 时, \n最少的数据库访问次数为: %d\n", cache, ans_A);
}

int DatabaseCache(int* data, int cache)
{
    
}