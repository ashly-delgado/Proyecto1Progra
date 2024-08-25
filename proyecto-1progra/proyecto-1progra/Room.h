#pragma once
#include <iostream>
class Room {
public:
	int number;
	int numberOfSeats;
	double price;
public:
	Room();
	Room(int number, int numberOfSeats, double price);
	~Room();

	//setters
	void setNumber(int);
	void setNumberOfSeats(int);
	void setPrice(double);

	//getters
	int getNumber();
	int getNumberOfSeats();
	double getPrice();
};

