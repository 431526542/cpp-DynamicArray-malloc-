#pragma once

//�⺻
/*
typedef struct _tagArr
{
	int* pInt;
	int Count;
	int MaxCount;
}tArr;

//������ �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);
//������ �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);
//������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);
//���Ҵ�
void Reallocate(tArr* _pArr);*/

//����
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
//��������
void bubble_sort(myArr* iArr);
//��������
void selection_sort(myArr* iArr);
//������
void Quick_sort(myArr* iArr, int start, int end);
