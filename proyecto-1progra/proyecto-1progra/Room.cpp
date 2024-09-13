#include "Room.h"
#include <iostream>

Room::Room() {

	number = 0;
	numberOfSeats = 0;
	price = 0;
	rowsQuantities = 0;
	seatsPerRows = 0;
	scheduleCounter = 0;
	schedule = new Schedule[0];
}

Room::Room(int number, int numberOfSeats, double price, int rowsQuantities, int seatsPerRows) {
	this->number = number;
	this->numberOfSeats = numberOfSeats;
	this->price = price;
	this->rowsQuantities = rowsQuantities;
	this->seatsPerRows = seatsPerRows;
	schedule = nullptr;
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
Schedule Room::getSchedule(int i) {
	return schedule[i];
}
Schedule* Room::getSchedule() {
	return schedule;
}
int Room::getScheduleCounter() {
	return scheduleCounter;
}
int Room::getRowsQuantities() {
	return rowsQuantities;
}
int Room::getSeatsPerRows() {
	return seatsPerRows;
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
void Room::setRowsQuantities(int rowsQuantities) {
	this->rowsQuantities = rowsQuantities;
}
void Room::setSeatsPerRows(int seatsPerRows) {
	this->seatsPerRows = seatsPerRows;
}
void Room::setSchedule(Schedule _schedule) {
	int newSize;
	newSize = scheduleCounter + 1;
	resizeArray(schedule, scheduleCounter, newSize);
	schedule[scheduleCounter] = _schedule;
	scheduleCounter = newSize;
}

void Room::resizeArray(Schedule*& schedule, int& sizeFrom, int newSize) {
	Schedule* newArr = new Schedule[newSize];
	for (int i = 0; i < sizeFrom && i < newSize; ++i) {
		newArr[i] = schedule[i];
	}
	if (sizeFrom != 0) {
		delete[] schedule;
	}
	schedule = newArr;
}

void Room::setScheduleCounter(int scheduleCounter) {
	this->scheduleCounter = scheduleCounter;
}