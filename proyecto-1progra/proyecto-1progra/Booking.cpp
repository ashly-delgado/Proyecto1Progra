#include "Booking.h"
#include <iostream>

Booking::Booking() {
	totalPrice = 0;
	bookingNumber = 0;
	movieId = 0;
	scheduleId = 0;
	quantitiesOfSeats = 0;
	price = 0;
	idBooking = 0;
}
Booking::Booking(double totalPrice, int bookingNumber, int movieId, int scheduleId, int quantitiesOfSeats, int price, int idBooking) {
	this->totalPrice = totalPrice;
	this->bookingNumber = bookingNumber;
	this->movieId = movieId;
	this->scheduleId = scheduleId;
	this->quantitiesOfSeats = quantitiesOfSeats;
	this->price = price;
	this->idBooking = idBooking;

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
int Booking::getQuantitiesOfSeats() {
	return quantitiesOfSeats;
}
int Booking::getPrice() {
	return price;
}
int Booking::getIdBooking() {
	return idBooking;
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
void Booking::setQuantitiesOfSeats(int quantitiesOfSeats) {
	this->quantitiesOfSeats = quantitiesOfSeats;
}
void Booking::setPrice(int price) {
	this->price = price;
}
void Booking::setIdBooking(int idBooking) {
	this->idBooking = idBooking;
}