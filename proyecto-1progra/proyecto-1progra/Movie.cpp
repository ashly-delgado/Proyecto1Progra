#include "Movie.h"
#include <iostream>

Movie::Movie() {
	name = "";
	year = 0;
	time = 0;
	country = "";
	review = 0;

}

Movie::Movie(std::string name, int year, int time, std::string country, int review, Room room) {
	this->name = name;
	this->year = year;
	this->time = time;
	this->country = country;
	this->review = review;
	this->room = room;
}
Movie::~Movie() {

}

//gets metodos
std::string Movie::getName() {
	return name;
}
int Movie::getYear() {
	return year;
}
int Movie::getTime() {
	return time;
}
std::string Movie::getCountry() {
	return country;
}
int Movie::getReview() {
	return review;
}
Room Movie::getRoom() {
	return room;
}
//sets metodos
void Movie::setName(std::string name) {
	this->name = name;
}
void Movie::setYear(int year) {
	this->year = year;
}
void Movie::setTime(int time) {
	this->time = time;
}
void Movie::setCountry(std::string country) {
	this->country = country;
}
void Movie::setReview(int review) {
	this->review = review;
}
void Movie::setRoom(Room room) {
	this->room = room;
}