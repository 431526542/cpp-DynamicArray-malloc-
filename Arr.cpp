#include "Arr.h"
#include<iostream>
#include <vector>

//�⺻
/*
void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->Count = 0;
	_pArr->MaxCount = 2;
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->Count = 0;
	_pArr->MaxCount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
	//�� ������ �Ҵ��� ������ �� �־���?
	if (_pArr->Count >= _pArr->MaxCount)
	{
		//���Ҵ�
		Reallocate(_pArr);
	}
	//������ �߰�
	_pArr->pInt[_pArr->Count++] = _iData;
}

void Reallocate(tArr* _pArr)
{
	//2�� ��ū ������ �Ҵ� �Ѵ�.
	int* nArr = (int*)malloc(_pArr->MaxCount * 2 * sizeof(int));
	//������ �ִ� �������ִ� ������ ���ο� ������ �����Ѵ�.
	for (int i = 0; i < _pArr->Count; ++i)
	{
		nArr[i] = _pArr->pInt[i];
	}
	//������ �ִ� ���� ����
	free(_pArr->pInt);
	//�迭�� ���� �Ҵ��� ������ ����Ű�� �Ѵ�
	_pArr->pInt = nArr;
	//MaxCount ������ ����
	_pArr->MaxCount = _pArr->MaxCount * 2;
}*/

//����

void Address(myArr* iArr)
{
	iArr->pint = (int*)malloc(sizeof(int) * 2);
	iArr->pCount = 0;
	iArr->pMaxCount = 2;
}

void clear(myArr* iArr)
{
	free(iArr->pint);
	iArr->pCount = 0;
	iArr->pMaxCount = 0;
}

void PushBack(myArr* iArr, int iData)
{
	if (iArr->pCount >= iArr->pMaxCount)
	{
		Re_Address(iArr);
	}
	iArr->pint[iArr->pCount++] = iData;
}

void Re_Address(myArr* iArr)
{
	int* newArr = (int*)malloc(iArr->pMaxCount * 2 * sizeof(int));
	for (int i = 0; i < iArr->pCount; ++i)
	{
		newArr[i] = iArr->pint[i];
	}
	free(iArr->pint);
	iArr->pint = newArr;
	iArr->pMaxCount = iArr->pMaxCount * 2;
}

//��������
void bubble_sort(myArr* iArr)
{
	for (int i = 0; i < iArr->pCount; ++i)
	{
		for (int j = 1; j < iArr->pCount - i; ++j)
		{
			if (iArr->pint[j - 1] > iArr->pint[j])
			{
				int temp = iArr->pint[j - 1];
				iArr->pint[j - 1] = iArr->pint[j];
				iArr->pint[j] = temp;
			}
		}
	}
}
//��������
void selection_sort(myArr* iArr)
{
	for (int i = 0; i < iArr->pCount; ++i)
	{
		int min = iArr->pint[i];
		int location = i;
		for (int j = i; j < iArr->pCount; ++j)
		{
			if (min > iArr->pint[j])
			{
				min = iArr->pint[j];
				location = j;
			}
		}
		int temp = iArr->pint[i];
		iArr->pint[i] = iArr->pint[location];
		iArr->pint[location] = temp;
	}
}
//������
void Quick_sort(myArr* iArr, int start, int end)
{
	if (start >= end) // ���Ұ� 1���� ��� �״�� �α�
		return;

	int pivot = start; // �Ǻ��� ù��° ����
	int i = start + 1, j = end, temp;

	while (i <= j) { // ������ ������ �ݺ�
		while (i <= end && (iArr->pint[i] <= iArr->pint[pivot])) { // �Ǻ����� ū ���� ã�� ������
			i++;
		}
		while (j > start && (iArr->pint[j] >= iArr->pint[pivot])) { // �Ǻ����� ���� ���� ã�� ������
			j--;
		}

		if (i > j) { // ������ ����. �Ǻ����� ���� ���� �Ǻ��� ��ü
			temp = iArr->pint[j];
			iArr->pint[j] = iArr->pint[pivot];
			iArr->pint[pivot] = temp;
		}
		else { // �������� �ʾҴٸ� i�� j�� ��ü
			temp = iArr->pint[i];
			iArr->pint[i] = iArr->pint[j];
			iArr->pint[j] = temp;
		}
	}

	Quick_sort(iArr, start, j - 1);
	Quick_sort(iArr, j + 1, end);
}


