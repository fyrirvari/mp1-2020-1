#include "Konvert.h"
#include <stdio.h>

Konvert::Konvert()  //конструктор по умолчанию без параметров в скобках
{
	d = 0;
}

Konvert::Konvert(double x)
{
	d = x;
}

Konvert::~Konvert()  //пустой
{
	//память освобождается автоматически
}

double Konvert::dume()
{
	return d * 100 / 2.5;
}

double Konvert::fut()
{
	return d * 3.28;
}

double Konvert::yard()
{
	return d * 1.1;
}

void Konvert::set(double x)
{
	d = x;
}

double Konvert::get()
{
	return d;
}

void Konvert::write()
{
	printf("%lf", d);
}