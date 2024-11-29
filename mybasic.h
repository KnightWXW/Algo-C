#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// 最大值与最小值
#define abs(x) (((x) < 0) ? (-x) : (x))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

// 随机数:
int GenerateRandomNum(int low, int high);

// 布尔值：
void PrintBool(bool b);

// 随机数组：
int *GenerateRandomVec(int low, int high, int len);
void FreeVec(int *vec);
void PrintVecElement(int *vec, int size);

// 随机二维数组:
int **GenerateRandomVec2D(int low, int high, int row, int col);
void FreeVec2D(int **vec, int row);
void PrintVecElement2D(int **vec, int row, int col);

// 随机字符串:
char *GenerateRandomString(int n, char *arr, int arrLen);
void FreeString(char *str);
void PrintString(char *str);

// 随机字符串数组:
char **GenerateRandomStringVecFixed(int row, int col, char *arr, int arrLen);
char **GenerateRandomStringVecUnfixed(int l, int low, int high, char *arr, int arrLen);
void FreeStringVec(char **arr, int l);
void PrintStringVec(char **arr, int l);