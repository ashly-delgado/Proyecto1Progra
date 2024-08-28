#include "Room.h"
#include <iostream>

Room::Room() {

	number = 0;
	numberOfSeats = 0;
	price = 0;
	scheduleCounter = 0;
	schedule = new Schedule[0];

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
Schedule Room::getSchedule(int i) {
	return schedule[i];
}
int Room::getScheduleCounter() {
	return scheduleCounter;
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
	delete[] schedule;
	schedule = newArr;
}
void Room::setScheduleCounter(int scheduleCounter) {
	this->scheduleCounter = scheduleCounter;
}