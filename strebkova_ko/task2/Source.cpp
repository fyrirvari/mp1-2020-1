#include <iostream>
#include <clocale>
#include <cstring>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

class Polynom
{
private:
	int n;
	double coeff[13];
public:
	Polynom()
	{
		n = 0;
		std::memset(coeff, 0, 13 * sizeof(double));
	}

	Polynom(int _n, double* _coeff)
	{
		n = _n;
		for (int i = 0; i <= n; i++)
			coeff[i] = _coeff[i];
	}

	int Set_Deg()
	{
		cout << "Введите степень полинома" << endl;
		cin >> n;
		return n;
	}

	void Set_Coeff(double* coeff)
	{
		cout << "Введите коэффициенты полинома" << endl;
		for (int i = 0; i <= n; i++)
		{
			cin >> coeff[i];
		}
	}

	void Show_Polynom()
	{
		for (int i = 0; i < n; i++)
			cout << coeff[i] << "x^" << n - i << " + ";
		cout << coeff[n] << endl;
	}

	void Deg_Polynom()
	{
		for (int i = 0; i <= n; i++)
			if (coeff[i] != 0)
			{
				cout << "Степень полинома: " << n - i << endl;
				break;
			}
	}

	void Find_Coeff()
	{
		cout << "Введите номер коэффицинта" << endl;
		int k;
		cin >> k;
		cout << k << "-ый кэффициент: " << coeff[k - 1] << endl;
	}

	void Calculate()
	{
		cout << "Введите х" << endl;
		double x;
		cin >> x;
		double f = 0;
		for (int i = 0; i <= n; i++)
		{
			f = f + coeff[i] * std::pow(x, n - i);
		}
		cout << "Значение полинома в точке х = " << x << ": " << f << endl;
	}

	void Derivative()
	{
		double Coeff[12];
		for (int i = 0; i < n; i++)
		{
			Coeff[i] = coeff[i];
			Coeff[i] = Coeff[i] * (n - i);
		}
		n = n - 1;
		Polynom F(n, Coeff);
		F.Show_Polynom();
	}

	Polynom operator=(const Polynom &F)
	{
		this->n = F.n;
		for (int i = 0; i <= n; i++)
			this->coeff[i] = F.coeff[i];
		return *this;
	}

	~Polynom() {}
};

void main()
{
	std::setlocale(LC_ALL, "Rus");
	Polynom F;
	int n = F.Set_Deg();
	double* coeff = new double [n + 1];
	F.Set_Coeff(coeff);
	F = Polynom(n, coeff);
	cout << "Выберете действие" << endl;
	cout << "1) Вывести полином на экран" << endl << "2) Узнать степень полинома" << endl << "3) Узнать значение коэффициента по его номеру" << endl;
	cout << "4) Вычислить значение полинома в заданной точке х" << endl << "5) Найти производную полинома" << endl;
	int mode;
	cin >> mode;
	switch (mode)
	{
		case 1:
			F.Show_Polynom();
			break;
		case 2:
			F.Deg_Polynom();
			break;
		case 3:
			cout << "Коэффициенты пронумерованы от 1 до " << n + 1 << ", слева направо" << endl;
			F.Find_Coeff();
			break;
		case 4:
			F.Calculate();
			break;
		case 5:
			F.Derivative();
			break;
	}
	delete[]coeff;
	system("pause");
}