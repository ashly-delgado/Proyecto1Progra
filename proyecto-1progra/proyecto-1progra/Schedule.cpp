#include "Schedule.h"
#include <iostream>

Schedule::Schedule() {
	date = "";
	startHour = 0;
	endHour = 0;
}

Schedule::Schedule(std::string date, int startHour, int endHour) {
	this->date = date;
	this->startHour = startHour;
	this->endHour = endHour;
}

Schedule::~Schedule() {

}

//gets metodos
std::string Schedule::getDate() {
	return date;
}
int Schedule::getStartHour() {
	return startHour;
}
int Schedule::getEndHour() {
	return endHour;
}

//sets metodos
void Schedule::setDate(std::string date) {
	this->date = date;
}
void Schedule::setStartHour(int startHour) {
	this->startHour = startHour;
}
void Schedule::setEndHour(int endHour) {
	this->endHour = endHour;
}
void Schedule::createSeatsMap(int rowsQuantities, int seatsPerRows) {
	seatsMap = new int* [rowsQuantities];
	for (int i = 0; i < rowsQuantities; i++)
	{
		seatsMap[0] = new int[seatsPerRows];
	}
}