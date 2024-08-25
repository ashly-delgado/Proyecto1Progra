#include "Sale.h"
#include <iostream>

Sale::Sale() {
	idCustomer = "";
	cardNumber = "";
}
Sale::Sale(std::string idCustomer, std::string cardNumber) {
	this->idCustomer = idCustomer;
	this->cardNumber = cardNumber;
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

//sets metodos
void Sale::setIdCustomer(std::string idCustomer) {
	this->idCustomer = idCustomer;
}
void Sale::setCardNumber(std::string cardNumber) {
	this->cardNumber = cardNumber;
}