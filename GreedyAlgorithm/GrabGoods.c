#include "../Mybasic/mybasic.h"

//      Huawei: 货物抓取

//      码头抓取货物，优先抓取编号连续数目最多的货物，
//      如果多个货物数目相同，优先抓取最左侧的货物。
//      如果货物被抓取后，右侧货物自动向左侧补齐。
//      输出抓取完货物的次数。
//      示例1：
//          输入：{8,8,8,5,5,5,8,1,1,2,3}
//          输出：6

int GrabGoods(int *goods, int l);

int main()
{
    int n = GenerateRandomNum(0, 20);
    int *vec = GenerateRandomVec(1, 3, n);
    PrintVecElement(vec, n);
    int ans_A = GrabGoods(vec, n);
    printf("抓取完货物的次数为 %d\n", ans_A);
    FreeVec(vec);
}

// 贪心：
// Time: O(N)
// Space: O(N)
int GrabGoods(int *goods, int l)
{
    int ans = 0;
    while (l > 0)
    {
        int kIndex = 0;
        int kCnt = 0;
        int i = 0;
        int pre = goods[0];
        int cnt = 0;
        for (i = 0; i < l; i++)
        {
            if (goods[i] == pre)
            {
                cnt++;
            }
            else
            {
                if (cnt > kCnt)
                {
                    kCnt = cnt;
                    kIndex = i - kCnt;
                }
                cnt = 1;
                pre = goods[i];
            }
        }
        if (cnt > kCnt)
        {
            kCnt = cnt;
            kIndex = i - kCnt;
        }
        for (int i = kIndex + kCnt; i < l; i++)
        {
            goods[i - kCnt] = goods[i];
        }
        l -= kCnt;
        ans++;
    }
    return ans;
}