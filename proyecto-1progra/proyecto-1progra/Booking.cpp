#include "Booking.h"
#include <iostream>

Booking::Booking() {
	totalPrice = 0;
	bookingNumber = 0;
	movieId = 0;
	scheduleId = 0;
}
Booking::Booking(double totalPrice, int bookingNumber, int movieId, int scheduleId) {
	this->totalPrice = totalPrice;
	this->bookingNumber = bookingNumber;
	this->movieId = movieId;
	this->scheduleId = scheduleId;
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
int Booking::getMovieId() {
	return movieId;
}
int Booking::getScheduleId() {
	return scheduleId;
}

//sets metodos
void Booking::setTotalPrice(double totalPrice) {
	this->totalPrice = totalPrice;
}
void Booking::setBookingNumber(int bookingNumber) {
	this->bookingNumber = bookingNumber;
}
void Booking::setMovieId(int movieId) {
	this->movieId = movieId;
}
void Booking::setScheduleId(int schedueleId) {
	this->scheduleId = scheduleId;
}