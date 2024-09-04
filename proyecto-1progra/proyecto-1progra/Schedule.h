#pragma once
#include <iostream>
class Schedule {
private:
	std::string date;
	int startHour;
	int endHour;
	int** seatsMap;

public:
	Schedule();
	Schedule(std::string date, int starHours, int endHours);

	~Schedule();

	//setters
	void setDate(std::string);
	void setStartHour(int);
	void setEndHour(int);

	//getters
	std::string getDate();
	int getStartHour();
	int getEndHour();


	void createSeatsMap(int, int);
	void changeSeatStatus(int, int);
	void showSeats(int, int);
};

