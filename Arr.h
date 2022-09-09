#pragma once

//기본
/*
typedef struct _tagArr
{
	int* pInt;
	int Count;
	int MaxCount;
}tArr;

//데이터 초기화 함수
void InitArr(tArr* _pArr);
//데이터 메모리 해제 함수
void ReleaseArr(tArr* _pArr);
//데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);
//재할당
void Reallocate(tArr* _pArr);*/

//정렬
struct myArr
{
	int* pint;
	int pCount;
	int pMaxCount;
};
void Address(myArr* iArr);
void clear(myArr* iArr);
void PushBack(myArr* iArr, int iData);
void Re_Address(myArr* iArr);
//버블정렬
void bubble_sort(myArr* iArr);
//선택정렬
void selection_sort(myArr* iArr);
//퀵정렬
void Quick_sort(myArr* iArr, int start, int end);
