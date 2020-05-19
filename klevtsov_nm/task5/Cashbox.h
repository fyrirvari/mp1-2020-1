#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
class Product
{
protected:
	std::string barcode;
	std::string title;
	double price;
	double discount;
public:
	Product(const std::string& barcode = "0000", const std::string& title = "", double price = 0, double discount = -1);
	Product(const Product&);
	~Product();

	void setBarcode(const std::string&);
	void setTitle(const std::string&);
	void setPrice(double);
	void setDiscount(double);
	std::string getBarcode() const;
	std::string getTitle() const;
	double getPrice() const;
	double getDiscount() const;

	Product& operator=(const Product&);
	bool operator==(const Product&) const;
	bool operator!=(const Product&) const;
	bool operator<(const Product&) const;
	bool operator>(const Product&) const;
	bool operator<=(const Product&) const;
	bool operator>=(const Product&) const;

	friend std::istream& operator>>(std::istream&, Product&);
	friend std::ostream& operator<<(std::ostream&, const Product&);
};

//----------------------------------------------------------------------------------
class Stock
{
protected:
	std::map<Product, size_t> products;
public:
	Stock(const std::string& path = "products_list.txt");
	Stock(const Stock&);
	~Stock();

	void readFromFile(const std::string& path = "products_list.txt");
	void setProducts(const std::map<Product, size_t>&);
	std::map<Product, size_t> getProducts() const;

	Stock& operator=(const Stock&);
	friend class Cashbox;
};

//----------------------------------------------------------------------------------
class Cashbox
{
private:
	std::string barcode;
	std::map<Product, size_t> check;
	Stock& stock;
public:
	Cashbox(Stock& stock);
	~Cashbox();

	void scan(const std::string&);
	std::pair<const Product, size_t> getInfo();
	void add();
	void remove();
	double amount();
	std::string createCheck();
};