#include <iostream>
#include <string>

class Temperature
{
private:
	double temp;
public:
	Temperature(double temp = 0)
	{
		set_temp(temp);
	}

	Temperature(const Temperature &temperature)
	{
		set_temp(temperature.temp);
	}

	void set_temp(double temp)
	{
		this->temp = temp;
	}

	double get_temp()
	{
		return this->temp;
	}

	void print()
	{
		std::cout << "Temperature: " << this->temp << " C" << std::endl;
	}

	Temperature& operator= (const Temperature &temperature)
	{
		set_temp(temperature.temp);
		return *this;
	}

	double fahrenheit()
	{
		return get_temp() * 9 / 5 + 32;
	}

	double kelvin()
	{
		return get_temp() + 273.15;
	}

	double rankine()
	{
		return get_temp() * 9 / 5 + 491.67;
	}

	double reaumur()
	{
		return get_temp() * 4 / 5;
	}
};

double get_temp(Temperature &temp, std::string &unit)
{
	int variable;
	do
	{
		std::cout << "Select:" << std::endl
			<< "1)Celsius" << std::endl
			<< "2)Fahrenheit" << std::endl
			<< "3)Kelvin" << std::endl
			<< "4)Rankine" << std::endl
			<< "5)Reaumur" << std::endl;
		std::cin >> variable;
	} while (variable < 1 || variable > 5);
	switch (variable)
	{
	case 1: unit = " C"; return temp.get_temp(); break;
	case 2: unit = " F"; return temp.fahrenheit(); break;
	case 3: unit = " K"; return temp.kelvin(); break;
	case 4: unit = " Ra"; return temp.rankine(); break;
	case 5: unit = " R"; return temp.reaumur(); break;
	}
}

int main(void)
{
	Temperature temp;
	std::string unit;
	int variable;
	while (true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1)Set temperature (Celsius)" << std::endl
			<< "2)Get temperature" << std::endl
			<< "3)Exit" << std::endl;
		std::cin >> variable;
		switch (variable)
		{
		case 1:
			double t;
			std::cout << "Enter temperature (Celsius): ";
			std::cin >> t;
			temp.set_temp(t);
			break;
		case 2:
			std::cout << "Temperature: " << get_temp(temp, unit) << unit << std::endl;
			break;
		case 3:
			return 0;
			break;
		}
	}
}