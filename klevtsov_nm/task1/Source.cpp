#include <iostream>
#include <string>

class Temperature
{
private:
	double t;
public:
	Temperature(double t = 0)
	{
		this->t = t;
	}

	Temperature(const Temperature &other)
	{
		this->t = other.t;
	}

	~Temperature() {}

	void setTemp(double t)
	{
		this->t = t;
	}

	double getTemp()
	{
		return t;
	}

	void print()
	{
		std::cout << "Temperature: " << t << " C" << std::endl;
	}

	Temperature& operator =(const Temperature &other)
	{
		this->t = other.t;
		return *this;
	}

	Temperature operator +(const Temperature &other)
	{
		Temperature temp(this->t + other.t);
		return temp;
	}

	Temperature operator -(const Temperature &other)
	{
		Temperature temp(this->t - other.t);
		return temp;
	}

	bool operator ==(const Temperature &other)
	{
		return this->t == other.t;
	}

	bool operator !=(const Temperature &other)
	{
		return !(this->t == other.t);
	}

	friend std::istream& operator >>(std::istream &in, Temperature &temp)
	{
		in >> temp.t;
		return in;
	}

	friend std::ostream& operator <<(std::ostream &out, const Temperature &temp)
	{
		out << temp.t;
		return out;
	}

	double toFahrenheit()
	{
		return t * 9 / 5 + 32;
	}

	double toKelvin()
	{
		return t + 273.15;
	}

	double toRankine()
	{
		return t * 9 / 5 + 491.67;
	}

	double toReaumur()
	{
		return t * 4 / 5;
	}
};

double getTemp(Temperature &temp, std::string &unit)
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
	case 1: unit = " C"; return temp.getTemp();
	case 2: unit = " F"; return temp.toFahrenheit();
	case 3: unit = " K"; return temp.toKelvin();
	case 4: unit = " Ra"; return temp.toRankine();
	case 5: unit = " R"; return temp.toReaumur();
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
			temp.setTemp(t);
			break;
		case 2:
			std::cout << "Temperature: " << getTemp(temp, unit) << unit << std::endl;
			break;
		case 3:
			return 0;
			break;
		}
		std::cout << std::endl;
	}
}