#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort()
{
}


QuickSort::~QuickSort()
{
}

//��������
/*
ѡ��һ����׼������׼�ƶ��������м䣬ʹ����ߵ����ݶ�С�ڻ�׼���ұߵ��������ڻ�׼
�ݹ黮�֣�������Ԫ�ص���1����ʱ������������
*/

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partion(int arr[], int low, int high)
{
	int privot = arr[low];          //ѡ���һ��Ԫ����Ϊ��׼
									//�ƶ�����ָ�����м��ƶ���������׼�ƶ����м䣬low��high�е�ĳһ��һ����ָ���׼��
	while (low < high)
	{
		while ((low < high) && arr[high] >= privot)             //����ұߵ����Ȼ�׼�������ƶ��������佻�������ȥ
			high--;
		swap(arr, low, high);
		while ((low < high) && arr[low] <= privot)
			low++;
		swap(arr, low, high);
	}
	return low;         //��low=high��ʱ����ֹͣ���֣�����low��high���ƶ��Ĺ����У�����һ����ָ���׼�ģ����ﷵ�أ�low��ʵ���ǻ�׼�������е�����
}

//�ݹ黮�֣������ֵ�һ��Ԫ�ص�ʱ����������������
void QSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int idx = partion(arr, low, high);
		//�ݹ黮�ֻ������������飬����������������
		QSort(arr, low, idx - 1);
		QSort(arr, idx + 1, high);
	}
}

void QuickSort::qucikSort(int arr[], int n)
{
	QSort(arr, 0, n - 1);
}