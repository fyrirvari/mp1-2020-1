#include <iostream>
#include <locale.h>
#include "DM.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	cout << "Введите длину массива: ";
	cin >> k;

	DM mas1(k);
	cout << "Длина массива: " << mas1.get_n() << '\n';

	cout << "Введите новую длину массива: ";
	cin >> k;
	mas1.set_n(k);
	cout << "Новая длина массива: " << mas1.get_n() << '\n';

	cout << "Вводим значение элементов: ";
	for (int i = 0; i < k; i++)
	{
		double y;
		cin >> y;
		mas1.set_element(i, y);
	}

	cout << "Выводим массив: ";
	for (int i = 0; i < k; i++)
	{
		cout << mas1.get_element(i) << " ";
	}
	cout << endl;

	system("pause");
}