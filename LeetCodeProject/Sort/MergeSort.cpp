#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

//�鲢����
/*
ʹ�÷���˼�룺��������������������ģ����䰴���������кϲ����ϲ�����µ��������飬�����������ֺϲ�
*/

void merge(int arr[], int low, int mid, int high)
{
	int *temp = new int(high - low + 1);//����һ���µ����飬��ԭ����ӳ���ȥ 
	int i = low;//�������鿪ʼλ��
	int j = mid + 1;//�������鿪ʼλ��
	int t = 0;//��ʱ�ռ�ָ��

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}

	//�����ʣ��Ԫ������temp��
	while (i <= mid)
		temp[t++] = arr[i++];

	//���ұ�ʣ��Ԫ������temp��
	while (j <= high)
		temp[t++] = arr[j++];

	//���ںϺ�����ݿ�����ԭ�������ݶ�Ӧ���ӿռ���
	t = 0;
	while (low <= high)
		arr[low++] = temp[t++];
}

void MergeSort::mergeSort(int arr[], int low, int high)
{
	if (low < high) {
		int mid = (low + high) / 2;

		//���������ں�����
		mergeSort(arr, low, mid);

		//���������ں�����
		mergeSort(arr, mid + 1, high);

		//�Ѿ�����ѡ�õ���������������ں�
		merge(arr, low, mid, high);
	}
}
