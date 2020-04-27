#include "Cashbox.h"

Product::Product(const std::string& barcode, const std::string& title, double price, double discount) : barcode(barcode), title(title), price(price)
{
	this->discount = discount != -1 ? discount : (rand() % 11) * 5;
}

Product::Product(const Product& other) : barcode(other.barcode), title(other.title), price(other.price), discount(other.discount) {}

Product::~Product() {}

void Product::setBarcode(const std::string& barcode)
{
	this->barcode = barcode;
}

void Product::setTitle(const std::string& title)
{
	this->title = title;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setDiscount(double discount)
{
	this->discount = discount;
}

std::string Product::getBarcode() const
{
	return barcode;
}

std::string Product::getTitle() const
{
	return title;
}

double Product::getPrice() const
{
	return price;
}

double Product::getDiscount() const
{
	return discount;
}

Product& Product::operator=(const Product& other)
{
	this->barcode = other.barcode;
	this->title = other.title;
	this->price = other.price;
	this->discount = other.discount;
	return *this;
}

bool Product::operator==(const Product& other) const
{
	return this->barcode == other.barcode && this->title == other.title && this->price == other.price;
}

bool Product::operator!=(const Product& other) const
{
	return !(*this == other);
}

bool Product::operator<(const Product& other) const
{
	return this->barcode < other.barcode;
}

bool Product::operator>(const Product& other) const
{
	return this->barcode > other.barcode;
}

bool Product::operator<=(const Product& other) const
{
	return this->barcode <= other.barcode;
}

bool Product::operator>=(const Product& other) const
{
	return this->barcode >= other.barcode;
}

std::istream& operator>>(std::istream& in, Product& product)
{
	in >> product.barcode >> product.price;
	std::getline(in, product.title);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
	out << product.barcode << " " << product.price << " " << product.title;
	return out;
}

//----------------------------------------------------------------------------------------
Stock::Stock(const std::string& path)
{
	readFromFile(path);
}

Stock::Stock(const Stock& other) : products(other.products) {}

Stock::~Stock() {}

void Stock::readFromFile(const std::string& path)
{
	std::fstream file;
	file.open(path, std::fstream::in);
	if (!file.is_open())
	{
		throw std::exception("File not open!");
	}
	else
	{
		products.clear();
		while (!file.eof())
		{
			Product product;
			size_t amount;
			file >> amount >> product;
			products.emplace(product, amount);
		}
	}
	file.close();
}

void Stock::setProducts(const std::map<Product, size_t>& products)
{
	this->products = products;
}

std::map<Product, size_t> Stock::getProducts() const
{
	return products;
}

Stock& Stock::operator=(const Stock& other)
{
	this->products = other.products;
	return *this;
}

//----------------------------------------------------------------------------------------
Cashbox::Cashbox(const std::string& path) : Stock(path), barcode("0000") {}

Cashbox::~Cashbox() {}

void Cashbox::scan(const std::string& barcode)
{
	this->barcode = barcode;
}

std::pair<const Product, size_t> Cashbox::getInfo()
{
	for (auto product : products)
	{
		if (product.first.getBarcode() == barcode)
		{
			return product;
		}
	}
	throw std::exception("There is no such product in Stock.");
}

void Cashbox::add()
{
	auto prod = getInfo();
	if (prod.second == 0)
	{
		throw std::exception("There is no such product in Stock.");
	}
	else
	{
		check[prod.first]++;
		products[prod.first]--;
	}
}

void Cashbox::remove()
{
	auto prod = getInfo();
	size_t count = check[prod.first];
	check.erase(prod.first);
	products[prod.first] += count;
}

double Cashbox::amount()
{
	double amount = 0;
	for (auto product : check)
	{
		amount += product.first.getPrice() * (1 - product.first.getDiscount() / 100) * product.second;
	}
	return amount;
}

std::string Cashbox::createCheck()
{
	double amount = 0;
	std::stringstream ss;
	ss << "Ltd \"Klevts\'s shop\"\n"
		<< "C. Nizhny Novgorod, st. Gagarin Avenue 23\n"
		<<	"Opening hours: 08:00 - 23:00 seven days a week\n";
	for (auto product : check)
	{
		double amt = product.first.getPrice() * (1 - product.first.getDiscount() / 100) * product.second;
		ss << std::fixed << std::setprecision(2)
			<< std::setw(30) << std::left << product.first.getTitle() << " " << std::setw(8) << product.first.getPrice() << "rub*" << std::setw(2) << product.second
			<< "\tdiscount - " << std::setw(5) << product.first.getDiscount() << "\%\t=" << std::setw(8) << amt << "\n";
		amount += amt;
	}
	ss << "_____________\nTotal amount =" << amount << "\n"
		<< "Thank you for your purchase!";
	check.clear();
	return ss.str();
}