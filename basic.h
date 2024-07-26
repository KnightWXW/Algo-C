#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int GenerateRandomNum(int low, int high);
extern int *GenerateRandomVec(int low, int high, int len);
extern void FreeRandomVec(int *vec);
void PrintVecElement(int *vec, int size);