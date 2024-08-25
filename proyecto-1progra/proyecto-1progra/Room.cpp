#include "Room.h"
#include <iostream>

Room::Room() {

	number = 0;
	numberOfSeats = 0;
	price = 0;

}

Room::Room(int number, int numberOfSeats, double price) {
	this->number = number;
	this->numberOfSeats = numberOfSeats;
	this->price = price;
	
}

Room::~Room() {

}
//gets metodos
int Room::getNumber() {
	return number;
}
int Room::getNumberOfSeats() {
	return numberOfSeats;
}
double Room::getPrice() {
	return price;
}

//sets metodos
void Room::setNumber(int number) {
	this->number = number;
}
void Room::setNumberOfSeats(int numberOfSeats) {
	this->numberOfSeats = numberOfSeats;
}
void Room::setPrice(double price) {
	this->price = price;
}