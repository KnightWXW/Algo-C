#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int GenerateRandomNum(int low, int high);
int *GenerateRandomVec(int low, int high, int len);
void FreeVec(int *vec);
void PrintVecElement(int *vec, int size);