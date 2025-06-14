#include "../Mybasic/mybasic.h"

//      Huawei: 汽车租赁

//      某公司计划组织一次外出团建，准备向租车公司租赁车辆。
//      已知该公司有若干个部门，depts[i] 表示第 i 个部门的员工数量。
//      在乘车时需要遵循：
//          同一部门的所有员工必须搭乘同一辆车，
//          不同部门的员工不能搭乘同一辆车。
//      有多家租车公司各提供了一种车型方案，记录于 plans，
//      plans[i] 表示第 i 家公司提供的方案，每种方案提供了多种车型，
//      plans[i][j] 表示该方案中第 j 类车型的核载人数（不同车型的核载人数可能相同）。
//      请选择一家公司的方案，使得每个部门租用合适车型的车后（每种车型的可租赁数量不限），
//      总空位最少。请返回所选方案的下标；
//      若有多种空位最少的方案，则返回其中下标最小的；若没有符合要求的，请返回 -1。
//      示例 1：
//          输入：depts = [10,8,15]
//               plans = [[8,15,12],[20,4,15,4],[15,8]]
//          输出：0
//          解释：因为同一部门的所有员工必须搭乘同一辆车，
//               所以必须选择核载人数大于等于部门人数的车辆。
//          方案 plans[0] 最少的总空位为：(12-10)+(8-8)+(15-15) = 2
//              depts[0] = 10，选用 plans[0][2] 的车型，其核载人数为 12，大于等于 10
//              depts[1] = 8，选用 plans[0][0] 的车型，其核载人数为 8，大于等于 8
//              depts[2] = 15，选用 plans[0][1] 的车型，其核载人数为 15，大于等于 15
//          方案 plans[1] 最少的总空位为：(15-10)+(15-8)+(15-15) = 12
//          注意： 1）只使用了核载人数 15 的车型（不同部门可租赁同一型号的车），其他车型未使用；
//                2）不允许拼车，如： depts[0]、depts[1] 两个部门，
//                  不能搭乘在一个核载人数为 20 的车上。
//          方案 plans[2] 最少的总空位为：(15-10)+(8-8)+(15-15) = 5
//          方案 0、1、2 的总空位分别是 2、12、5，因此选择 plans[0]，返回下标 0。
//      示例 2：
//          输入：depts = [5,9]
//               plans = [[4],[6,10],[5,11]]
//          输出：1
//              1）方案 plans[0] 无法满足搭乘条件；
//              2）方案 plans[1] 最少的总空位为：(6-5)+(10-9) = 2；
//              3）方案 plans[2] 最少的总空位为：(5-5)+(11-9) = 2；
//          plans[1] 和 plans[2] 的最少空位均为 2，返回其中下标最小的 1。
//      示例 3：
//          输入：depts = [10,10]
//               plans = [[2,9,8,3],[7]]
//          输出：-1
//          解释：由于同一部门的所有员工需要搭乘同一辆车，不允许将同一部门的员工拆分乘坐，所给方案
//          中最大的车型核载人数不足 10 人，因此没有符合要求的方案，返回 -1。
//      提示：
//          1 <= depts.length <= 1000
//          1 <= plans.length, plans[i].length <= 1000
//          1 <= plans[i][j], depts[i] <= 10^5

int RentCars1(int *depts, int deptsSize, int **plans, int row, int *col);

int main()
{
    int n1 = 3;
    int depts1[] = {10, 8, 15};
    int row1 = 3;
    int col1[] = {3, 4, 2};
    int **plans1 = (int **)malloc(sizeof(int *) * row1);
    for (int i = 0; i < row1; i++)
    {
        plans1[i] = (int *)malloc(sizeof(int) * col1[i]);
    }
    plans1[0][0] = 8;
    plans1[0][1] = 15;
    plans1[0][2] = 12;
    plans1[1][0] = 20;
    plans1[1][1] = 4;
    plans1[1][2] = 15;
    plans1[1][3] = 4;
    plans1[2][0] = 15;
    plans1[2][1] = 8;
    int ans1 = RentCars1(depts1, n1, plans1, row1, col1);
    printf("所选方案的下标为 %d\n", ans1);
    FreeVec2D(depts1, row1);

    int n2 = 2;
    int depts2[] = {5, 9};
    int row2 = 3;
    int col2[] = {1, 2, 2};
    int **plans2 = (int **)malloc(sizeof(int *) * row2);
    for (int i = 0; i < row2; i++)
    {
        plans2[i] = (int *)malloc(sizeof(int) * col2[i]);
    }
    plans2[0][0] = 4;
    plans2[1][0] = 6;
    plans2[1][1] = 10;
    plans2[2][0] = 5;
    plans2[2][1] = 11;
    int ans2 = RentCars1(depts2, n2, plans2, row2, col2);
    printf("所选方案的下标为 %d\n", ans2);
    FreeVec2D(depts2, row2);
}

// 贪心：
// Time: O(NlogN)
// Space: O(logN)
int RentCars1(int *depts, int deptsSize, int **plans, int row, int *col)
{

}