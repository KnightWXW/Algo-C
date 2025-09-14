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

#define MAX_BOARD_LEN 10000

int ExchangeTestingTimeAtMostOnce(int *arr, int l, int **board, int n);

int main()
{
    int l1 = 9;
    int nums1[9] = {6, 2, 2, 1, 7, 5, 7, 3, 4};
    int n1 = 3;
    int **vec1 = (int **)malloc(sizeof(int *) * n1);
    for (int i = 0; i < n1; i++)
    {
        vec1[i] = (int *)malloc(sizeof(int) * n1);
    }
    vec1[0][0] = 4;
    vec1[0][1] = 1;
    vec1[0][2] = 3;
    vec1[1][0] = 1;
    vec1[1][1] = 2;
    vec1[1][2] = 5;
    vec1[2][0] = 7;
    vec1[2][1] = 6;
    vec1[2][2] = 2;
    PrintVecElement(nums1, l1);
    PrintVecElement2D(vec1, n1, n1);
    int ans_A = ExchangeTestingTimeAtMostOnce(nums1, l1, vec1, n1, n1);
    printf(" 仪器最早在接受第 %d 个数字(从1开始计数) 时完成测试。\n", ans_A);

    int l2 = 12;
    int nums2[12] = {8, 9, 2, 7, 10, 1, 1, 1, 4, 5, 5, 3};
    int n2 = 4;
    int **vec2 = (int **)malloc(sizeof(int *) * n2);
    for (int i = 0; i < n2; i++)
    {
        vec2[i] = (int *)malloc(sizeof(int) * n2);
    }
    vec2[0][0] = 5;
    vec2[0][1] = 9;
    vec2[0][2] = 5;
    vec2[1][3] = 1;
    vec2[1][0] = 1;
    vec2[1][1] = 4;
    vec2[1][2] = 2;
    vec2[1][3] = 8;
    vec2[2][0] = 2;
    vec2[2][1] = 8;
    vec2[2][2] = 1;
    vec2[2][3] = 3;
    vec2[3][0] = 3;
    vec2[3][1] = 1;
    vec2[3][2] = 7;
    vec2[3][3] = 2;
    PrintVecElement(nums2, l2);
    PrintVecElement2D(vec2, n2, n2);
    int ans_B = ExchangeTestingTimeAtMostOnce(nums2, l2, vec2, n2, n2);
    printf(" 仪器最早在接受第 %d 个数字(从1开始计数) 时完成测试。\n", ans_B);
}

int ExchangeTestingTimeAtMostOnce(int *arr, int l, int **board, int n)
{
    int used[MAX_BOARD_LEN] = 0;
}

/*
int arr[10000000]
int check(int  mid, int* nums, int ** board, iny n)
{
	int cnt = 0;
	memset(arr, 0, sizeof(int));
	for(int i = 0; i < mid, i++){
		arr[nums[i]] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
		{
			CNT += arr[board[i][j]];
		}
	}
	if(cnt < n){
		return 0
	}
	for(int i = 0; i < n; i++){
		int ta = 0;
		int tb = 0;
		for(int j = 0; j < n; j++)
		{
			ta += arr[board[i][j]];
			tb += arr[board[j][i]];
		}
		if(ta >= n - 1 || tb >= n - 1){
			return 1
		}
	}
	return 0;
}

int ExchangeTestingTimeAtMostOnce(int *arr, int l, int **board, int n)
{
	int n = n;
	int c = 1;
	int k = l;
	while(c <= k){
		int mid = (c + k) / 2;
		if(check(mid, nums, board, n)){
			k = mid - 1;
		}else{
			c = mid + 1;
		}
	}
	return c;
}
*/