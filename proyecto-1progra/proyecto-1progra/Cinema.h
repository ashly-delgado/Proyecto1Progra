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


	void subMenuMantenimiento();
	bool subMenuReserva();
	void showMenu();
	void subMenuVenta();
	void subShowFilesMenu();
	void about();
	void showMoviesList();
	void addMovieToArray(Movie movie);
	void resizeArray(Movie*& array, int& sizeFrom, int newSize);
	void resizeBookingArray(Booking*& array, int& sizeFrom, int newSize);
	void resizeSaleArray(Sale*& array, int& sizeFrom, int newSize);
	void subAddRoom();
	void listSeats();
	void menuReservar();
	void listBooking();
	void fillSale();
	void listSale();

	std::string readString();
	int getInt();
	double getDouble();
	void subAddSchedule();
	Movie addMovie();
	
};

