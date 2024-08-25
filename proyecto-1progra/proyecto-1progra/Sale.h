#pragma once
#include <iostream>

class Sale {
private:
	std::string idCustomer;
	std::string cardNumber;

public:
	Sale();
	Sale(std::string idCustomer, std::string cardNumber);
	~Sale();

	//setters
	void setIdCustomer(std::string);
	void setCardNumber(std::string);

	//getters
	std::string getIdCustomer();
	std::string getCardNumber();
};

