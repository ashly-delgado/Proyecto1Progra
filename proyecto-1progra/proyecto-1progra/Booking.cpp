#include "Booking.h"
#include <iostream>

Booking::Booking() {
	totalPrice = 0;
	bookingNumber = 0;
}
Booking::Booking(double totalPrice, int bookingNumber) {
	this->totalPrice = totalPrice;
	this->bookingNumber = bookingNumber;
}
Booking::~Booking() {

}

//gets metodos
double Booking::getTotalPrice() {
	return totalPrice;
}
int Booking::getBookingNumber() {
	return bookingNumber;
}

//sets metodos
void Booking::setTotalPrice(double totalPrice) {
	this->totalPrice = totalPrice;
}
void Booking::setBookingNumber(int bookingNumber) {
	this->bookingNumber = bookingNumber;
}