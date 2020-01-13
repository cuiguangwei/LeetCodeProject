#include "stdafx.h"
#include "CountSort.h"


CountSort::CountSort()
{
}


CountSort::~CountSort()
{
}

int maxValue(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void CountSort::countSort(int arr[], int n)
{
	if (arr == nullptr || n == 0) return;

	int max = maxValue(arr, n);
	int *temp = (int *)malloc((max + 1) * sizeof(int));
	int a = sizeof(temp);
	memset(temp, 0, (max + 1) * sizeof(temp));//³õÊ¼»¯Îª0

	for (int i = 0; i < n; ++i) {
		temp[arr[i]]++;
	}

	int k = 0;
	for (int i = 0; i <= max; ++i) {
		for (int j = 0; j < temp[i]; j++) {
			arr[k++] = i;
		}
	}
}