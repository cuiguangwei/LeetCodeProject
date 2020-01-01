#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

//归并排序
/*
使用分治思想：假设两个子数组是有序的，将其按照有序序列合并，合并组成新的有序数组，再与其他部分合并
*/

void merge(int arr[], int low, int mid, int high)
{
	int *temp = new int(high - low + 1);//开辟一个新的数组，将原数组映射进去 
	int i = low;//左子数组开始位置
	int j = mid + 1;//右子数组开始位置
	int t = 0;//临时空间指针

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}

	//将左边剩余元素填充进temp中
	while (i <= mid)
		temp[t++] = arr[i++];

	//将右边剩余元素填充进temp中
	while (j <= high)
		temp[t++] = arr[j++];

	//将融合后的数据拷贝到原来的数据对应的子空间中
	t = 0;
	while (low <= high)
		arr[low++] = temp[t++];
}

void MergeSort::mergeSort(int arr[], int low, int high)
{
	if (low < high) {
		int mid = (low + high) / 2;

		//左子数组融合排序
		mergeSort(arr, low, mid);

		//右子数组融合排序
		mergeSort(arr, mid + 1, high);

		//已经排序选好的子数组进行有序融合
		merge(arr, low, mid, high);
	}
}
