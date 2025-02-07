#include "../Mybasic/mybasic.h"

//      Huawei: 至多交换一次的测试时间

//      有一批指示灯，放在正方形的测试仪器board上进行测试,
//      board[i][j]表示第i行第j列位置上指示灯的型号，
//      现进行测试仪器依次接收nums中的数字，规则如下：
//          每接收一个数字，board中所有的型号值等于该数字的指示灯都会点亮
//          当board有任意一行或者一列被完全点亮时，表示仪器测试完成
//          有一次交换board中任意两盏指示灯的机会(也可以不用)
//      请问仪器最早在接受第几个数字(从1开始计数)时完成测试？
//      示例1：
//      输入：
//          nums = [6,2,2,1,7,5,7,3,4]
//          board = [[4,1,3],
//                   [1,2,5],
//                   [7,6,2]]
//      输出：2
//      示例2：
//      输入：
//          nums = [8,9,2,7,10,1,1,1,4,5,5,3]
//          board = [[5,9,5,1],
//                   [1,4,2,8],
//                   [2,8,1,3],
//                   [3,1,7,2]]
//      输出：6

void printVecElement(vector<int> vec);
void print2DVecElement(vector<vector<int>> vec);

int ExchangeTestingTimeAtMostOnce(vector<int> arr, vector<vector<int>> board);

int main()
{
    vector<int> nums1 = {6, 2, 2, 1, 7, 5, 7, 3, 4};
    vector<vector<int>> vec1 = {{4, 1, 3}, {1, 2, 5}, {7, 6, 2}};
    printVecElement(nums1);
    print2DVecElement(vec1);
    int ans_A = ExchangeTestingTimeAtMostOnce(nums1, vec1);
    printf(" 仪器最早在接受第 %d 个数字(从1开始计数) 时完成测试。\n", ans_A);

    vector<int> nums2 = {8, 9, 2, 7, 10, 1, 1, 1, 4, 5, 5, 3};
    vector<vector<int>> vec2 = {{5, 9, 5, 1}, {1, 4, 2, 8}, {2, 8, 1, 3}, {3, 1, 7, 2}};
    printVecElement(nums2);
    print2DVecElement(vec2);
    int ans_B = ExchangeTestingTimeAtMostOnce(nums2, vec2);
    printf(" 仪器最早在接受第 %d 个数字(从1开始计数) 时完成测试。\n", ans_B);
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ExchangeTestingTimeAtMostOnce(vector<int> arr, vector<vector<int>> board)
{
    
}