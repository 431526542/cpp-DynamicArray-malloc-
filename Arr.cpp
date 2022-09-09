#include "Arr.h"
#include<iostream>
#include <vector>

//기본
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
	//힙 영역에 할당한 공간에 다 넣었나?
	if (_pArr->Count >= _pArr->MaxCount)
	{
		//재할당
		Reallocate(_pArr);
	}
	//데이터 추가
	_pArr->pInt[_pArr->Count++] = _iData;
}

void Reallocate(tArr* _pArr)
{
	//2배 더큰 공간을 할당 한다.
	int* nArr = (int*)malloc(_pArr->MaxCount * 2 * sizeof(int));
	//기존에 있던 공간에있는 정보를 새로운 공간에 복사한다.
	for (int i = 0; i < _pArr->Count; ++i)
	{
		nArr[i] = _pArr->pInt[i];
	}
	//기존에 있는 공간 해제
	free(_pArr->pInt);
	//배열이 새로 할당한 공간을 가르키게 한다
	_pArr->pInt = nArr;
	//MaxCount 변경점 적용
	_pArr->MaxCount = _pArr->MaxCount * 2;
}*/

//정렬

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

//버블정렬
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
//선택정렬
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
//퀵정렬
void Quick_sort(myArr* iArr, int start, int end)
{
	if (start >= end) // 원소가 1개인 경우 그대로 두기
		return;

	int pivot = start; // 피봇은 첫번째 원소
	int i = start + 1, j = end, temp;

	while (i <= j) { // 엇갈릴 때까지 반복
		while (i <= end && (iArr->pint[i] <= iArr->pint[pivot])) { // 피봇보다 큰 값을 찾을 때까지
			i++;
		}
		while (j > start && (iArr->pint[j] >= iArr->pint[pivot])) { // 피봇보다 작은 값을 찾을 때까지
			j--;
		}

		if (i > j) { // 엇갈린 상태. 피봇보다 작은 값과 피봇과 교체
			temp = iArr->pint[j];
			iArr->pint[j] = iArr->pint[pivot];
			iArr->pint[pivot] = temp;
		}
		else { // 엇갈리지 않았다면 i와 j를 교체
			temp = iArr->pint[i];
			iArr->pint[i] = iArr->pint[j];
			iArr->pint[j] = temp;
		}
	}

	Quick_sort(iArr, start, j - 1);
	Quick_sort(iArr, j + 1, end);
}


