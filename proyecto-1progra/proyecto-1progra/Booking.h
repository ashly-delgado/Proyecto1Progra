#pragma once
#include <iostream>

class Booking {
private:
	double totalPrice;
	int bookingNumber;

public:
	Booking();
	Booking(double totalPrice, int bookingNumber);
	~Booking();

	//setters
	void setTotalPrice(double);
	void setBookingNumber(int);

	//getters
	double getTotalPrice();
	int getBookingNumber();
};

