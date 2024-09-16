#pragma once
#include <iostream>
#include "Movie.h"
#include "Schedule.h"
#include "Room.h"
#include "Booking.h"
#include "Sale.h"
class Cinema {
private:

public:
	Cinema();
	~Cinema();


	void maintenanceSubMenu();
	bool reservation();
	void showMenu();
	void saleMenu();
	void subShowFilesMenu();
	void about();
	void showMoviesList();
	void addMovieToArray(Movie movie);
	void resizeArray(Movie*& array, int& sizeFrom, int newSize);
	void resizeBookingArray(Booking*& array, int& sizeFrom, int newSize);
	void resizeSaleArray(Sale*& array, int& sizeFrom, int newSize);
	void AddRoom();
	void listSeats();
	void bookingSubMenu();
	void listBooking();
	void fillSale();
	void listSale();

	std::string readString();
	int getInt();
	double getDouble();
	void AddSchedule();
	Movie addMovie();

};

