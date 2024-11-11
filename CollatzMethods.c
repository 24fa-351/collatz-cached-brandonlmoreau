
#include "CollatzMethods.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include "Cache.h"




int* makeRandomNumberArray(int max, int min, int size)//returns new allocated array full of random numbers within constraints
{
	int* newArray = (int*)malloc(size * sizeof(int));
	if (newArray == NULL)
	{
		printf("failed");
		return NULL;
	}
	size--;
	do
	{
		newArray[size] = (rand()%(max-min+1))+min;
		size--;
	} while (size>=0);
	return newArray;
}
int collatzAlgorithm(int input)
{
	int steps = 0;
	while (input!=1)
	{
		if ((input % 2)==0)
		{
			input = input / 2;
		}
		else
		{
			input = (input * 3) + 1;
		}
		steps++;
	}

	return steps;
}

int collatz_LRU_AlgorithmWrapper(int N, int *cacheHit, cacheEntry cache[],int cacheSize)
{
	int iteration = checkCache(cache,cacheSize, N);
	if(iteration!=-1)//exists, reform cache, return
	{
		moveToFront(cache, cacheSize, iteration);
		*cacheHit = *cacheHit + 1;
		return cache[0].steps;
	}

	else//doesnt exist, add to cache, return
	{

		int val = collatzAlgorithm(N);
		pushToFront(cache, cacheSize, newCache(N, val));
		return val;
	}
}

int collatz_MRU_AlgorithmWrapper(int N, int* cacheHit, cacheEntry cache[], int cacheSize)
{
	int iteration = checkCache(cache, cacheSize, N);
	if (iteration != -1)//exists, return value from cache, dont reform cache
	{
		*cacheHit = *cacheHit + 1;
		return cache[iteration].steps;
	}

	else if((iteration == -1)&&(cache[cacheSize-1].N>0))//pop and push front of cache if full
	{
		int val = collatzAlgorithm(N);
		cache[0] = newCache(N,val);
		return val;
	}

	else//doesnt exist, add to cache, return
	{
		int val = collatzAlgorithm(N);
		pushToFront(cache, cacheSize, newCache(N, val));
		return val;
	}
}

