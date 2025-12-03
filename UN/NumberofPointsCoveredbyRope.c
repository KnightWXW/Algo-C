#include "../Mybasic/mybasic.h"

//      给定一个 有序数组arr，代表坐落在X轴上的点，
//      给定一个正数K，代表绳子的长度，返回绳子最多压中几个点？
//      注意：即使绳子边缘处盖住点也算盖住

int NumberofPointsCoveredbyRope_A(int *vec, int l, int k);
int CompareInt(const void *a, const void *b);

int main()
{
    int n = generateRandomNum(1, 50);
    int *arr = GenerateRandomVec(1, 100, n);
    qsort(arr, n, sizeof(int), CompareInt); 
    int k = generateRandomNum(1, 50);
    int ans = NumberofPointsCoveredbyRope_A(arr, n, k);
    PrintVecElement(arr, n);
    printf("绳子最多压中 %d 个点 \n", ans);
    FreeVec(arr);
}

int CompareInt(const void *a, const void *b);
{
    int *tema = (int *)a;
    int *temb = (int *)b;
    return *tema - *temb;
}

int NumberofPointsCoveredbyRope_A(int *vec, int l, int k)
{
    
}