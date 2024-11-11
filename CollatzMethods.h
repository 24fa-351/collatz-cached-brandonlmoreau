#pragma once
#ifndef CollatzMethods
#define CollatzMethods
#include "Cache.h"

int* makeRandomNumberArray(int max, int min, int size);
int collatzAlgorithm(int input);
int collatz_LRU_AlgorithmWrapper(int N, int* cacheHit, cacheEntry cache[], int cacheSize);
int collatz_MRU_AlgorithmWrapper(int N, int* cacheHit, cacheEntry cache[], int cacheSize);


#endif


 