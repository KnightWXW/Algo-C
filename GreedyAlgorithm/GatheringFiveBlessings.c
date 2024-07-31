#include "../mybasic.h"

//      Huawei ���帣

//      ��Ϊ���������ϲ���ּ�ӭ�´����
//      ���ϰ���������ǿ������г�������Ƹ�����ҵ�����ɷ���������
//      �� 0 �� 1 ��ɵĳ���Ϊ 5 ���ַ�������ÿ�������õ��ĸ�����
//      ÿһλ����һ�ָ�����1 ��ʾ�Ѿ���øø����������͸��������� 1 �ţ�
//      �����ȡһ��С�� 10 ���Ŷӣ�����Ŷ������Լ���������帣��
//      ��������
//          �������ɸ���0��1��ɵĳ��ȵ���5���ַ����������Ŷ���ÿ���˸�����������
//          ע��1��1��Ҳ������һ���Ŷ�
//          ע��2��1�˿�����0��5�Ÿ����������������ظ�
//      �������
//          ������Ŷ�����ܴ���������帣
//      ʾ��һ
//          ����
//              11001,11101
//          ���
//              0
//      ʾ����
//          ����
//              11101,10111
//          ���
//              1

#define NUM_FIVE 5

int GatheringFiveBlessings(char **vec, int n);

int main()
{
    int n = GenerateRandomNum(1, 10);
    char arr1[] = {'0', '1'};
    char **strs = GenerateRandomStringVecFixed(n, 5, arr1, 2);
    PrintStringVec(strs, n);
    int ans_A = GatheringFiveBlessings(strs, n);
    FreeStringVec(strs, n);
    printf("���Ŷ������Լ��� %d ���帣 ", ans_A);
}

int GatheringFiveBlessings(char **vec, int n)
{
    int ans = n + 1;
    int *cnt = (int *)malloc(NUM_FIVE * sizeof(int));
    memset(cnt, 0, NUM_FIVE * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUM_FIVE; j++)
        {
            cnt[j] += (vec[i][j] == '0' ? 0 : 1);
        }
    }
    PrintVecElement(cnt, 5);
    for (int i = 0; i < NUM_FIVE; i++)
    {
        ans = min(ans, cnt[i]);
    }
    return ans;
}