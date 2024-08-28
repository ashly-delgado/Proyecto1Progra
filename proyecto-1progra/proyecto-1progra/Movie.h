#pragma once
#include "Room.h"
#include <iostream>


class Movie {
private:
	std::string name;
	int year;
	int time;
	std::string country;
	int review; // 0 al 10 
	Room room;

public:
	Movie();

	Movie(std::string name, int year, int time, std::string country, int review, Room room);

	~Movie();

	//setters
	void setName(std::string);
	void setYear(int);
	void setTime(int);
	void setCountry(std::string);
	void setReview(int);
	void setRoom(Room);

	//getters
	std::string getName();
	int getYear();
	int getTime();
	std::string getCountry();
	int getReview();
	Room getRoom();
};

