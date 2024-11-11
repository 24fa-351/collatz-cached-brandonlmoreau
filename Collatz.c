#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "CollatzMethods.h"
#include "Cache.h"

int main(int argc,char *argv[])
{
    FILE *file;
    int nSize = atoi(argv[3]);
    int nSizeSaved = nSize;
    int cacheType;
    int cacheSize = atoi(argv[5]);
    int* numberArray;
    int steps=0;
    cacheEntry* cache;
    int cacheUsage = 0;
    double hitPercentage;
    
    cacheType = checkCacheType(argv[4]);
    numberArray = makeRandomNumberArray(atoi(argv[1]), atoi(argv[2]), nSize);
    cache = (struct cacheEntry*)malloc(cacheSize * sizeof(cacheEntry));
    file = fopen("myCSV.csv", "w");
    fprintf(file, "count,N,steps till 1\n");
    nSize--;
    while (nSize >= 0)
    {
        if (cacheType == 0)//no cache
        {
            steps = collatzAlgorithm(numberArray[nSize]);
        }
        else if (cacheType == 1)//LRU
        {
            steps = collatz_LRU_AlgorithmWrapper(numberArray[nSize], &cacheUsage, cache, cacheSize);
        }
        else if (cacheType == 2)//MRU
        {
            steps = collatz_MRU_AlgorithmWrapper(numberArray[nSize], &cacheUsage, cache, cacheSize);
        }
        fprintf(file, "%d,%d,%d\n", nSize, numberArray[nSize], steps);
        nSize--;
    }
    hitPercentage = (double)cacheUsage / nSizeSaved;
    printf("hit percentage: %lf\n", hitPercentage);//comes out to zero cause it most likely neds to be a float, can be tested by increasing odds by maniuplating the args to givea smaller number window
    fclose(file);
    free(numberArray);
    free(cache);

    return 0;
}
//y ou are here
