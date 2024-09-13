#include "Booking.h"
#include <iostream>

Booking::Booking() {
	totalPrice = 0;
	bookingNumber = 0;
	movieId = 0;
	scheduleId = 0;
	quantitiesOfSeats = 0;
	price = 0;
	state = 0;
}

Booking::Booking(double totalPrice, int bookingNumber, int movieId, int scheduleId, int quantitiesOfSeats, int price, int state) {
	this->totalPrice = totalPrice;
	this->bookingNumber = bookingNumber;
	this->movieId = movieId;
	this->scheduleId = scheduleId;
	this->quantitiesOfSeats = quantitiesOfSeats;
	this->price = price;
	this->state = state;

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
int Booking::getState() {
	return state;
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
void Booking::setState(int state) {
	this->state = state;
}


void Booking::setQuantitiesOfSeats(int quantitiesOfSeats) {
	this->quantitiesOfSeats = quantitiesOfSeats;
	matrixSeatsPerBooking = new int* [quantitiesOfSeats];
	for (int i = 0; i < quantitiesOfSeats; i++)
	{
		matrixSeatsPerBooking[i] = new int[2];
	}
	for (int i = 0; i < quantitiesOfSeats; i++)
	{
		matrixSeatsPerBooking[i][0] = 0;
		matrixSeatsPerBooking[i][1] = 0;
	}
}
void Booking::setPrice(int price) {
	this->price = price;
}


void Booking::addSeatsToList(int row,int rowValue,int columnValue) {

	matrixSeatsPerBooking[row][0] = rowValue;
	matrixSeatsPerBooking[row][1] = rowValue;

}

int Booking::getSeatValue(int rows, int columns) {
	return matrixSeatsPerBooking[rows][columns];
}