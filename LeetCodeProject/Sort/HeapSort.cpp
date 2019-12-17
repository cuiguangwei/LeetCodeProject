#include "stdafx.h"
#include "HeapSort.h"


HeapSort::HeapSort()
{
}


HeapSort::~HeapSort()
{
}

/**
* ��ɸѡ������start֮�⣬start~end������󶥶ѵĶ��塣
* ����֮��start~end��Ϊһ���󶥶ѡ�
* @param arr ����������
* @param start ��ʼָ��
* @param end ����ָ��
*/
void heapAdjust(int arr[], int start, int end) {
	int temp = arr[start];

	for (int i = 2 * start + 1; i <= end; i *= 2) {
		//���Һ��ӵĽڵ�ֱ�Ϊ2*i+1,2*i+2

		//ѡ������Һ��ӽ�С���±�
		if (i < end && arr[i] < arr[i + 1]) {
			i++;
		}
		if (temp >= arr[i]) {
			break; //�Ѿ�Ϊ�󶥶ѣ�=�����ȶ��ԡ�
		}
		arr[start] = arr[i]; //���ӽڵ�����
		start = i; //��һ��ɸѡ
	}

	arr[start] = temp; //������ȷ��λ��
}

void HeapSort::swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void HeapSort::heapSort(int arr[], int n)
{
	if (arr == nullptr || n == 0)
		return;

	//�����󶥶�
	for (int i = n / 2; i >= 0; i--) {
		heapAdjust(arr, i, n - 1);
	}

	for (int i = n - 1; i >= 0; i--) {
		swap(arr, 0, i);
		heapAdjust(arr, 0, i - 1);
	}
}
