#include "../Mybasic/mybasic.h"

//      LeetCode 2739. 总行驶距离

//      链接：https://leetcode.cn/problems/total-distance-traveled/

//      卡车有两个油箱。给你两个整数，
//      mainTank 表示主油箱中的燃料（以升为单位），
//      additionalTank 表示副油箱中的燃料（以升为单位）。
//      该卡车每耗费 1 升燃料都可以行驶 10 km。每当主油箱使用了 5 升燃料时，
//      如果副油箱至少有 1 升燃料，则会将 1 升燃料从副油箱转移到主油箱。
//      返回卡车可以行驶的最大距离。
//      注意：从副油箱向主油箱注入燃料不是连续行为。
//      这一事件会在每消耗 5 升燃料时突然且立即发生。
//      示例 1：
//          输入：mainTank = 5, additionalTank = 10
//          输出：60
//          解释：
//              在用掉 5 升燃料后，主油箱中燃料还剩下 (5 - 5 + 1) = 1 升，行驶距离为 50km 。
//              在用掉剩下的 1 升燃料后，没有新的燃料注入到主油箱中，主油箱变为空。
//              总行驶距离为 60km 。
//      示例 2：
//          输入：mainTank = 1, additionalTank = 2
//          输出：10
//          解释：
//              在用掉 1 升燃料后，主油箱变为空。
//              总行驶距离为 10km 。
//      提示：
//          1 <= mainTank, additionalTank <= 100

int DistanceTraveled_A(int mainTank, int additionalTank);
int DistanceTraveled_B(int mainTank, int additionalTank);

int main()
{
    int mainTank = GenerateRandomNum(1, 99);
    int additionalTank = GenerateRandomNum(1, 100);
    int ans1 = DistanceTraveled_A(mainTank, additionalTank);
    int ans2 = DistanceTraveled_B(mainTank, additionalTank);
    printf("主油箱中的燃料为 %d 时, 副油箱中的燃料为 %d 时，卡车可以行驶的最大距离为 %d\n", mainTank, additionalTank, ans1);
    printf("主油箱中的燃料为 %d 时, 副油箱中的燃料为 %d 时，卡车可以行驶的最大距离为 %d\n", mainTank, additionalTank, ans2);
}

// 模拟：
// Time: O(N)
// Space: O(1)
int DistanceTraveled_A(int mainTank, int additionalTank)
{
    int ans = 0;
    while (mainTank >= 5)
    {
        mainTank -= 5;
        ans += 50;
        if (additionalTank > 0)
        {
            mainTank++;
            additionalTank--;
        }
    }
    ans += 10 * mainTank;
    return ans;
}

// 数学：
// Time: O(1)
// Space: O(1)
int DistanceTraveled_B(int mainTank, int additionalTank)
{
    return 10 * (mainTank + min((mainTank - 1) / 4, additionalTank));
}