#include <iostream>
#include <clocale>
#include <cmath>

int NOD(int a, int b)
{
	do
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	} while ((a != 0) && (b != 0));
	if (a == 0)
		return b;
	else 
		return a;
}

class Rational_Fraction
{
private:
	int numerator, denominator;
public:
	Rational_Fraction()
	{
		numerator = 0;
		denominator = 1;
	}

	Rational_Fraction (int a, int b)
	{
		numerator = a;
		denominator = b;
		if (denominator == 0)
			std::cout << "Некорректная дробь" << std::endl;
		else 
			Simplified_Fraction ();
	}

	void Simplified_Fraction()
	{
		int nod;
		nod = NOD(fabs(numerator), fabs(denominator));
		numerator = numerator / nod;
		denominator = denominator / nod;
		if (denominator < 0)
		{
			numerator = numerator * (-1);
			denominator *= denominator * (-1);
		}
	}
	Rational_Fraction operator+ (const Rational_Fraction &fraction)
	{
		int NOK = this->denominator * fraction.denominator / NOD(this->denominator, fraction.denominator);
		int res_num = this->numerator * NOK / this->denominator + fraction.numerator * NOK / fraction.denominator;
		Rational_Fraction res = Rational_Fraction(res_num, NOK);
		return res;
	}

	Rational_Fraction operator- (const Rational_Fraction &fraction)
	{
		int NOK = this->denominator * fraction.denominator / NOD(this->denominator, fraction.denominator);
		int res_num = this->numerator * NOK / denominator - fraction.numerator * NOK / fraction.denominator;
		Rational_Fraction res = Rational_Fraction(res_num, NOK);
		return res;
	}

	Rational_Fraction operator* (const Rational_Fraction &fraction)
	{
		int res_num = this->numerator * fraction.numerator;
		int res_denom = this->denominator * fraction.denominator;
		Rational_Fraction res = Rational_Fraction(res_num, res_denom);
		return res;
	}

	Rational_Fraction operator/ (const Rational_Fraction &fraction)
	{
		int res_num = this->numerator * fraction.denominator;
		int res_denom = this->denominator * fraction.numerator;
		Rational_Fraction res = Rational_Fraction(res_num, res_denom);
		return res;
	}
	void Show()
	{
		std::cout << numerator << "/" << denominator << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	Rational_Fraction a, b, res;
	char slash;
	int num_a, denom_a;
	do
	{
		std::cout << "Введите первую дробь в формате a/b: ";
		std::cin >> num_a >> slash >> denom_a;
		a = Rational_Fraction(num_a, denom_a);
	} while (denom_a == 0);
	int num_b, denom_b;
	do
	{
		std::cout << "Введите вторую дробь в формате a/b: ";
		std::cin >> num_b >> slash >> denom_b;
		b = Rational_Fraction(num_b, denom_b);
	} while (denom_b == 0);
	std::cout << "Выберете операцию с дробями:" << std::endl;
	std::cout << "1 - сложение" << std::endl << "2 - разность" << std::endl << "3 - произведение" << std::endl << "4 - деление" << std::endl;
	int operation;
	std::cin >> operation;
	switch (operation)
	{
		case 1:
			res = a + b;
			break;
		case 2:
			res = a - b;
			break;
		case 3:
			res = a * b;
			break;
		case 4:
			res = a / b;
			break;
	}
	res.Show();
	system("pause");
}