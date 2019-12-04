//冒泡法
/*
相邻元素比较：选择小的元素放在前面
非相邻元素比较，则是插入法的思想
*/

#include "stdafx.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::bubbleSort(int arr[], int n) {
	if (arr == nullptr || n == 0)
		return;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				/*int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;*/
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


//void BubbleSort::bubbleSort(int arr[], int n) {
//	if (arr == nullptr || n == 0)
//		return;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = n - 1; j > i; j--) {
//			if (arr[j] < arr[j - 1]) {
//				swap(arr, j - 1, j);
//			}
//		}
//	}
//}
//
//void BubbleSort::swap(int arr[], int i, int j) {
//	int temp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = temp;
//}


