#include<iostream>
#include<locale>

class DynamicArr
{
private:
	double* arr; //массив 
	int len; //длина массива

public:
	DynamicArr();
	DynamicArr(int size);
	DynamicArr(DynamicArr& x);
	~DynamicArr();
	DynamicArr& operator=(DynamicArr& x);

	int get_len(); //узнать длину массива
	void set_len(int f); //задать длину массива 

	double get(int x); //узнать элемент массива по индексу 
	void set(int x, double zn); //задать элемент массива по его индексу 

	double get_min_el(); //поиск минимального элемента 
	int test1(); //проверка на упорядоченность по убыванию
	int test2(); //проверка на упорядоченность по возрастанию 

	DynamicArr nechet(); //подмассив с нечётными индексами
};

DynamicArr::DynamicArr()
{
	arr = NULL;
	len = 0;
}
DynamicArr::DynamicArr(int size)
{
	len = size;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
DynamicArr::DynamicArr(DynamicArr& x)
{
	len = x.len;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = x.arr[i];
	}
}
DynamicArr::~DynamicArr()
{
	if (arr != NULL) free(arr);
}
DynamicArr& DynamicArr::operator=(DynamicArr& x)
{
	if (len != x.len)
	{
		free(arr);
		len = x.len;
		arr = new double[len];
	}
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
	return *this;
}
void DynamicArr::set_len(int f)
{
	if (len > 0)
		free(arr);
	len = f;
	arr = new double[len];
}
int DynamicArr::get_len()
{
	return len;
}
void DynamicArr::set(int x, double zn)
{
	arr[x] = zn;
}
double DynamicArr::get(int x)
{
	return arr[x];
}
double DynamicArr::get_min_el()
{
	double min = 100000000000;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int DynamicArr::test1()
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			return 0;
	}
	return 1;
}
int DynamicArr::test2()
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i + 1] < arr[i])
			return 0;
	}
	return 1;
}
DynamicArr DynamicArr::nechet()
{
	DynamicArr Result(len / 2);
	for (int i = 1; i < len; i += 2)
	{
		Result.arr[i / 2] = arr[i];
	}
	return Result;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	printf("Задайте размер массива: ");
	scanf_s("%d", &k);
	DynamicArr mas(k);
	printf("Размер массива: %d \n", mas.get_len());

	printf("Задайте новый размер массива: ");
	scanf_s("%d", &k);
	mas.set_len(k);
	printf("Новый размер массива: %d \n", mas.get_len());

	printf("Задайте значение элементов: ");
	for (int i = 0; i < k; i++)
	{
		double zn;
		scanf_s("%lf", &zn);
		mas.set(i, zn);
	}

	printf("Ваш массив: ");
	for (int i = 0; i < k; i++)
	{
		printf("%lf ", mas.get(i));
	}
	printf("\n");

	printf("Минимальный элемент: ");
	double r = mas.get_min_el();
	printf("%lf\n", r);

	if (mas.test1())
		printf("Упорядоченный по убыванию\n");
	if (mas.test2())
		printf("Упорядоченный по возрастанию\n");
	if (!mas.test1() && !mas.test2())
		printf("Не упорядоченный\n");

	DynamicArr Res = mas.nechet();
	printf("Ваш подмассив с нечётными индексами: ");
	for (int i = 0; i < Res.get_len(); i++)
	{
		printf("%lf ", (Res.get(i)));
	}
	printf("\n");

	system("pause");
}