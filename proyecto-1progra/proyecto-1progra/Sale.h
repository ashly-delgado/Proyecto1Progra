#pragma once
#include <iostream>

class Sale {
private:
	std::string idCustomer;
	std::string cardNumber;
	int idBooking;
	double total;
	int idSale;
public:
	Sale();
	Sale(std::string idCustomer, std::string cardNumber, int idBBoking,int idSale, double total);
	~Sale();

	//setters
	void setIdCustomer(std::string);
	void setCardNumber(std::string);
	void setIdBooking(int);
	void setIdSale(int);
	void setTotal(double);

	//getters
	double getTotal();
	int getIdBooking();
	int getIdSale();
	std::string getIdCustomer();
	std::string getCardNumber();
};

