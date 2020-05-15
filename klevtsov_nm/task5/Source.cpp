#include "Cashbox.h"

int main(void)
{
	srand(time(NULL));
	Cashbox cashbox;
	Stock stock;
	std::string barcode;
	std::pair<Product, double> product;
	int variable;
	do
	{
		system("cls");
		std::cout << "What is needed?" << std::endl
			<< "1) Scan" << std::endl
			<< "2) Get product information" << std::endl
			<< "3) Add product to check" << std::endl
			<< "4) Create check" << std::endl
			<< "5) Get total amount" << std::endl
			<< "6) Remove product from check" << std::endl
			<< "7) Exit" << std::endl;
		std::cout << "Your variable - ";
		std::cin >> variable;
		try
		{
			switch (variable)
			{
			case 1:
				std::cout << "Enter barcode: ";
				std::cin >> barcode;
				cashbox.scan(barcode);
				break;
			case 2:
				product = cashbox.getInfo(stock);
				std::cout << product.first << "\tquantity - " << product.second << std::endl;
				system("pause");
				break;
			case 3:
				cashbox.add(stock);
				break;
			case 4:
				system("cls");
				std::cout << cashbox.createCheck() << std::endl;
				system("pause");
				break;
			case 5:
				std::cout << cashbox.amount() << std::endl;
				system("pause");
				break;
			case 6:
				cashbox.remove(stock);
				break;
			}
		}
		catch (std::exception& ex) { std::cerr << ex.what() << std::endl; system("pause"); }
	} while (variable != 7);
	return 0;
}