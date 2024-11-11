#pragma once
#ifndef Cache
#define Cache

typedef struct
{
	int N;
	int steps;
}cacheEntry;


cacheEntry newCache(int N, int steps);

int checkCacheType(char* string);

void moveToFront(cacheEntry cache[], int size, int iterationToMove);

void pushToFront(cacheEntry cache[], int size, cacheEntry newNode);

#endif

