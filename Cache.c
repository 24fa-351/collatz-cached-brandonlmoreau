
#include "Cache.h"
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

cacheEntry newCache(int N, int steps)
{
	cacheEntry thisNode;
	thisNode.N = N;
	thisNode.steps = steps;
	return thisNode;
}

int checkCacheType(char* string)// check cache type once at startup to use strcmp less
{
	string[strcspn(string, "\n")] = '\0';
	string[strcspn(string, ",")] = '\0';

	if (strcmp(string,"LRU")==0)
	{
		return 1;
	}
	else if (strcmp(string, "MRU")==0)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void checkCache(cacheEntry cache[], int size, int N) //returns -1 unless cache holds N
{
	int count = 0;
	while ((count<size)&&(cache[count].N>=1))
	{
		//printf("cache checked[%d]: %d\n", count, cache[count].N);  // This will help see the values in the debugger

		if (N == cache[count].N)
		{
			return count;
		}
		count ++;
	}
	return -1;
}

void moveToFront(cacheEntry cache[], int size,int iterationToMove)
{
	cacheEntry holder = cache[iterationToMove];
	memmove(&cache[1],&cache[0], (iterationToMove) * sizeof(cacheEntry));//double check itToMov-1
	cache[0] = holder;
}
void pushToFront(cacheEntry cache[], int size, cacheEntry newNode)
{
	memmove(&cache[1], &cache[0], (size - 1) * sizeof(cacheEntry));
	cache[0] = newNode;
}

