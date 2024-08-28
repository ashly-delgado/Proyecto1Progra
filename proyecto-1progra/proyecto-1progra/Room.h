#pragma once
#include <iostream>
#include "Schedule.h"
class Room {
public:
	int number;
	int numberOfSeats;
	double price;
	Schedule* schedule;
	int scheduleCounter;
	int rowsQuantities;
	int seatsPerRows;

public:
	Room();
	Room(int number, int numberOfSeats, double price, int rowsQuantities, int seatsPerRows);
	~Room();

	//setters
	void setScheduleCounter(int);
	void setSchedule(Schedule);
	void setNumber(int);
	void setNumberOfSeats(int);
	void setPrice(double);
	void setRowsQuantities(int);
	void setSeatsPerRows(int);
	void resizeArray(Schedule*&, int&, int);
	//getters
	int getScheduleCounter();
	Schedule getSchedule(int);
	int getNumber();
	int getNumberOfSeats();
	int getRowsQuantities();
	int getSeatsPerRows();
	double getPrice();
};

