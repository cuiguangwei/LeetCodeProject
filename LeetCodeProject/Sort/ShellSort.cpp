#include "stdafx.h"
#include "ShellSort.h"


ShellSort::ShellSort()
{
}


ShellSort::~ShellSort()
{
}

void shellInsert(int arr[], int n, int d)
{
	for (int i = d; i < n; i++) {
		int j = i - d;
		int temp = arr[i];//带插入的数据
		while (j >= 0 && arr[j] > temp) {//从后向前，找到比其小的数的位置
			arr[j + d] = arr[j];//向后挪动
			j -= d;
		}

		if (j != i - d)//存在比其小的数 
			arr[j + d] = temp;
	}
}

void ShellSort::shellSort(int arr[], int n)
{
	if (arr == nullptr || n == 0) return;

	int d = n / 2;
	while (d >= 1) {
		shellInsert(arr, n, d);
		d /= 2;
	}
}