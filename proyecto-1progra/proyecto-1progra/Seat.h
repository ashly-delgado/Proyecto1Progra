#pragma once
#include <iostream>

class Seat {
private:
	int id;
	std::string state; //disponible| reservado| vendida

public:
	Seat();

	Seat(int id, std::string state);

	~Seat();

	//setters
	void setId(int);
	void setState(std::string);

	//getters
	int getId();
	std::string getState();

};
