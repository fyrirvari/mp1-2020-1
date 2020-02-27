#include <iostream>
#include "DM.h"

DM::DM()
{
	n = 0;
	arr = 0;
}

DM::DM(int q)
{
	n = q;
	arr = new double[n];  //выдел€ет пам€ть дл€ столького количества элементов, сколько мы хотим
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}

DM::~DM()
{
	if (n > 0)  //проверка на освобождение пам€ти. ≈сли n = 0, то удал€тьс€ не будет
	delete[]arr;
}

void DM::set_n(int f)
{
	if (n > 0)
	delete[]arr;
	n = f;
	arr = new double[n];  //выделили новую пам€ть
}

int DM::get_n()
{
	return n;
}

void DM::set_element(int x, double y)
{
	arr[x] = y;  //записывает в массив по заданному номеру элемента
}

double DM::get_element(int x)
{
	return arr[x];
}