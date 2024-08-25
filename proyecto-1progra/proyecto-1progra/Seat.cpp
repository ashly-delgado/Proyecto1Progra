#include "Seat.h"
#include <iostream>

Seat::Seat() {
	id = 0;
	state = "";
}
Seat::Seat(int id, std::string state) {
	this->id = id;
	this->state = state;
}
Seat::~Seat() {

}

//gets metodos
int Seat::getId() {
	return id;
}
std::string Seat::getState() {
	return state;
}

//sets metodos
void Seat::setId(int id) {
	this->id = id;
}
void Seat::setState(std::string state) {
	this->state = state;
}