#include "Sale.h"
#include <iostream>

Sale::Sale() {
	idCustomer = "";
	cardNumber = "";
	idBooking = 0;
	idSale = 0;
	total = 0;
}
Sale::Sale(std::string idCustomer, std::string cardNumber,int idBooking,int idSale, double total) {
	this->idCustomer = idCustomer;
	this->cardNumber = cardNumber;
	this->idBooking = idBooking;
	this->idSale = idSale;
	this->total = total;
}
Sale::~Sale() {

}

//gets metodos
std::string Sale::getIdCustomer() {
	return idCustomer;
}
std::string Sale::getCardNumber() {
	return cardNumber;
}
int Sale::getIdBooking() {
	return idBooking;
}
int Sale::getIdSale() {
	return idSale;
}
double Sale::getTotal() {
	return total;
}
//sets metodos
void Sale::setIdCustomer(std::string idCustomer) {
	this->idCustomer = idCustomer;
}
void Sale::setCardNumber(std::string cardNumber) {
	this->cardNumber = cardNumber;
}
void Sale::setIdBooking(int idBooking) {
	this->idBooking = idBooking;
}
void Sale::setIdSale(int idSale) {
	this->idSale = idSale;
}
void Sale::setTotal(double total) {
	this->total = total;
}
