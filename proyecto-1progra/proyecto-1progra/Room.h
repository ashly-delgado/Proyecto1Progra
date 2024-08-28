#include <iostream>
#include "Schedule.h"
class Room {
public:
	int number;
	int numberOfSeats;
	double price;
	Schedule* schedule;
	int scheduleCounter;
public:
	Room();
	Room(int number, int numberOfSeats, double price);
	~Room();

	//setters
	void setScheduleCounter(int);
	void setSchedule(Schedule);
	void setNumber(int);
	void setNumberOfSeats(int);
	void setPrice(double);
	void resizeArray(Schedule*&, int&, int);
	//getters
	int getScheduleCounter();
	Schedule getSchedule(int);
	int getNumber();
	int getNumberOfSeats();
	double getPrice();
};