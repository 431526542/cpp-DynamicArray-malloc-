#include<iostream>
#include"Arr.h"

int main()
{
	//�⺻
	/*
	tArr s;
	InitArr(&s);
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s, i);
	}
	ReleaseArr(&s);
	return 0;*/

	//����
	int addNum[5] = { 20,5,9,12,1 };
	myArr arr;
	Address(&arr);
	for (int i = 0; i < 5; ++i)
	{
		PushBack(&arr, addNum[i]);
	}
	//��������
	/*
	bubble_sort(&arr);
	*/
	//��������
	/*
	selection_sort(&arr);
	*/
	//������
	Quick_sort(&arr,0, 4);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << arr.pint[i] << std::endl;
	}
	clear(&arr);
	return 0;
}