#include "stdafx.h"
#include "SelectSort.h"


SelectSort::SelectSort()
{
}


SelectSort::~SelectSort()
{
}

void SelectSort::selectSort(int arr[], int n) {
	if (arr == nullptr || n == 0)
		return;

	int index = 0;
	for (int i = 0; i < n - 1; ++i) {
		index = i;
		for (int j = i + 1; j < n ; ++j) {
			if (arr[j] < arr[index]) {
				index = j;
			}			
		}
		if (index != i) {
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}