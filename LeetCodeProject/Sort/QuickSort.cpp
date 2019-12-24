#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

//快速排序：
/*
选择一个基准，将基准移动到数据中间，使得左边的数据都小于基准，右边的数都大于基准
递归划分，当数据元素等于1个的时候就是有序的了
*/

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partion(int arr[], int low, int high)
{
	int privot = arr[low];          //选择第一个元素作为基准
									//推动左右指针向中间移动，即将基准移动到中间，low和high中的某一个一定是指向基准的
	while (low < high)
	{
		while ((low < high) && arr[high] >= privot)             //如果右边的数比基准大，则不用移动，否则将其交换到左边去
			high--;
		swap(arr, low, high);
		while ((low < high) && arr[low] <= privot)
			low++;
		swap(arr, low, high);
	}
	return low;         //当low=high的时候则停止划分，由于low和high在移动的过程中，总有一个是指向基准的，这里返回，low其实就是基准在数组中的索引
}

//递归划分，当划分到一个元素的时候，子数组就是有序的
void QSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int idx = partion(arr, low, high);
		//递归划分划分左右子数组，让左右子数组有序
		QSort(arr, low, idx - 1);
		QSort(arr, idx + 1, high);
	}
}

void QuickSort::qucikSort(int arr[], int n)
{
	QSort(arr, 0, n - 1);
}