#include "Tabulator.h"

Section::Section(double rightBoarder, double leftBoarder):rightBoarder(rightBoarder), leftBoarder(leftBoarder) {}

Section::Section(const Section &other)
{
	this->leftBoarder = other.leftBoarder;
	this->rightBoarder = other.rightBoarder;
}

Section::~Section() {}

void Section::setSection(double rightBoarder, double leftBoarder)
{
	this->leftBoarder = leftBoarder;
	this->rightBoarder = rightBoarder;
}

void Section::setLeftBoarder(double boarder)
{
	this->leftBoarder = boarder;
}

void Section::setRightBoarder(double boarder)
{
	this->rightBoarder = boarder;
}

double Section::getLeftBoarder()
{
	return leftBoarder;
}

double Section::getRightBoarder()
{
	return rightBoarder;
}

std::string Section::getSection()
{
	return "[" + std::to_string(leftBoarder) + "," + std::to_string(rightBoarder) + "]";
}

Section& Section::operator =(const Section &other)
{
	this->leftBoarder = other.leftBoarder;
	this->rightBoarder = other.rightBoarder;
	return *this;

}

std::istream& operator >>(std::istream &in, Section &section)
{
	std::cout << "Enter left boarder: ";
	in >> section.leftBoarder;
	std::cout << "Enter right boarder: ";
	in >> section.rightBoarder;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Section &section)
{
	out << "[" + std::to_string(section.leftBoarder) + "," + std::to_string(section.rightBoarder) + "]" << std::endl;
	return out;
}

//--------------------------------------------------------------------------------
Tabulator::Tabulator(int amt, const Section &section, double(*func)(double)) : amt(amt), section(section), func(func) {}

Tabulator::Tabulator(int amt, double rightBoarder, double leftBoarder, double(*func)(double)) : amt(amt), section(rightBoarder, leftBoarder), func(func) {}

Tabulator::Tabulator(const Tabulator &other) : amt(other.amt), section(other.section), func(other.func) {}

Tabulator::~Tabulator() {}

void Tabulator::setFunction(double(*func)(double))
{
	this->func = func;
}

void Tabulator::setAmount(int amt)
{
	this->amt = amt;
}

void Tabulator::setSection(const Section &section)
{
	this->section = section;
}

void Tabulator::setSection(double rightBoarder, double leftBoarder)
{
	section.setSection(rightBoarder, leftBoarder);
}

double (*Tabulator::getFunction())(double)
{
	return func;
}

int Tabulator::getAmount()
{
	return amt;
}

Section Tabulator::getSection()
{
	return section;
}

void Tabulator::performTabulation()
{
	values.clear();
	double step = (section.getRightBoarder() - section.getLeftBoarder()) / (amt - 1);
	int i = 0;
	for (double x = section.getLeftBoarder(); i < amt; x += step, i++)
	{
		values.push_back(func(x));
	}
}

void Tabulator::printValues()
{
	for (size_t i = 0; i < values.size(); i++)
	{
		std::cout << values[i] << std::endl;
	}
}

void Tabulator::saveValues(std::string path = "test.txt")
{
	std::fstream file;
	file.open(path, std::fstream::out);
	if (!file.is_open())
	{
		std::cout << "File not open" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < values.size(); i++)
		{
			file << values[i] << std::endl;
		}
		std::cout << "Saving succeed" << std::endl;
	}
	file.close();
}

Tabulator& Tabulator::operator =(const Tabulator &other)
{
	this->amt = other.amt;
	this->section = other.section;
	this->func = other.func;
	return *this;
}