#include "stdafx.h"
#include "InsertSort.h"


InsertSort::InsertSort()
{
}


InsertSort::~InsertSort()
{
}

void InsertSort::insertSort(int arr[], int n)
{
	if (arr == nullptr || n == 0) return;

	for (int  i = 1; i < n; ++i) {
		int target = arr[i]; //´ý²åÈë
		int j = i;
		while (j > 0 && target < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = target;//²åÈë
	}
}