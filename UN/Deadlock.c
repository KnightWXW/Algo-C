#include "../Mybasic/mybasic.h"

//      Huawei: 死锁

//      某系统的进程可能占有和等待一些资源，
//      现给出在某一时刻dump的这些进程占有的等待的资源信息，
//      请按照如下简化规则分析哪些进程发生了死锁，请升序返回所有死锁的进程ID列表，或空列表[]。
//      简化规则如下：
//      如果某个进程P的任一扥等待资源被占有，则该进程必须等待，直到这些资源被释放，
//      等待期间，该进程不会释放所占有的资源
//      如果进程P所等待的资源全部都未被其他进程占有，则该进程必将释放所占有的资源
//      基于上书所述，如果一个进程因为所等待的资源一直被占有而无限等待下去，
//      则认为该进程发生了死锁
//      输入：
//          第一行为一个整数num,表示进程个数
//          第二行开始的num行，依次表示每个进程占有和等待资源的情况
//          格式为：进程ID(占有资源列表)(等待资源列表)
//              0<= 进程ID <= 100
//              0<= 资源编号 <= 300
//          每一行的输入中不会包含重复的资源编号
//          输入保证：每个资源最多只会被一个进程占有
//      输出:
//          升序返回所有死锁的进程ID列表，或空列表[]
//      示例1：
//          输入：
//              5
//              100 () (20)
//              1 (40 20) (10)
//              2 (10) (30 100)
//              3 (100 300) (40 0)
//              0 () (30)
//          输出：
//              [1, 2, 3 100]
//      示例2：
//          输入：
//              4
//              2 () (40 30)
//              1 (20) (30 40)
//              3 () ()
//              9 (40) (30)
//          输出：
//              []
//      示例3：
//          输入：
//              6
//              1 (10) (20 50)
//              2 (20) (30 60)
//              3 (30) (40)
//              5 (50) ()
//              6 (101) (202)
//              7 (202) (101)
//          输出：
//              [6, 7]

int* Deadlock(int* arr, int l, int* possess, int rowp, int colp, int** await, int rowa, int cola);

int main()
{
    int arr_a1[] = {100, 1, 2, 3, 0};
    int possess_a1 = {{}, {40, 20}, {10}, {100, 300}, {}};
    vector<vector<int>> await_a1 = {{20}, {10}, {30, 100}, {40, 0}, {30}};
    printVecElement(arr_a1);
    print2DVecElement(possess_a1);
    print2DVecElement(await_a1);
    vector<int> ans_a1 = Deadlock(arr_a1, possess_a1, await_a1);
    printf("所有死锁的进程ID列表为 :\n");
    printVecElement(ans_a1);

    vector<int> arr_a2 = {2, 1, 3, 9};
    vector<vector<int>> possess_a2 = {{}, {20}, {}, {40}};
    vector<vector<int>> await_a2 = {{40, 30}, {30, 40}, {}, {30}};
    printVecElement(arr_a2);
    print2DVecElement(possess_a2);
    print2DVecElement(await_a2);
    vector<int> ans_a2 = Deadlock(arr_a2, possess_a2, await_a2);
    printf("所有死锁的进程ID列表为 :\n");
    printVecElement(ans_a2);

    vector<int> arr_a3 = {1, 2, 3, 5, 6, 7};
    vector<vector<int>> possess_a3 = {{10}, {20}, {30}, {50}, {101}, {202}};
    vector<vector<int>> await_a3 = {{20, 50}, {30, 60}, {40}, {}, {202}, {101}};
    printVecElement(arr_a3);
    print2DVecElement(possess_a3);
    print2DVecElement(await_a3);
    vector<int> ans_a3 = Deadlock(arr_a3, possess_a3, await_a3);
    printf("所有死锁的进程ID列表为 :\n");
    printVecElement(ans_a3);
}



int* Deadlock(int* arr, int l, int* possess, int rowp, int colp, int** await, int rowa, int cola)
{

}