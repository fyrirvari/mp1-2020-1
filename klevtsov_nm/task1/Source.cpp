#include <iostream>

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
