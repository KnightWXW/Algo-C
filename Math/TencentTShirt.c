#include "../Mybasic/mybasic.h"

//      Tencent: 鹅厂文化衫问题

//      企鹅厂每年都会发文化衫，文化衫有很多种，
//      厂庆的时候，企鹅们都需要穿文化衫来拍照
//      一次采访中，记者随机遇到的企鹅，
//      企鹅会告诉记者还有多少企鹅跟他穿一种文化衫
//      我们将这些回答放在 answers 数组里，返回鹅厂中企鹅的最少数量。
//	    输入: answers = [1]    输出：2
//	    输入: answers = [1, 1, 2]    输出：5

int TencentTShirt_A(int* vec, int n);
int TencentTShirt_B(int* vec, int n);

int main()
{
    int n = GenerateRandomNum(0, 50);
    int* answers = GenerateRandomVec(1, 5, n);
    PrintVecElement(answers);
    int ans_A = TencentTShirt_A(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_A);
    int ans_B = TencentTShirt_B(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_B);
    FreeVec(answers);
}

int TencentTShirt_A(int* vec, int n)
{
    
}

int TencentTShirt_B(int* vec, int n)
{
   
}

