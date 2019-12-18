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
		int temp = arr[i];//�����������
		while (j >= 0 && arr[j] > temp) {//�Ӻ���ǰ���ҵ�����С������λ��
			arr[j + d] = arr[j];//���Ų��
			j -= d;
		}

		if (j != i - d)//���ڱ���С���� 
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