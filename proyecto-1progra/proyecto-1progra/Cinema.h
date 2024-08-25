#pragma once
#include <iostream>
#include "Movie.h"
#include "Schedule.h"
#include "Room.h"
class Cinema {
private:
	
public:
	Cinema(); 
	~Cinema();


	void subMenuMantenimiento();
	void subMenuReserva();
	void showMenu();
	void subMenuVenta();
	void subShowFilesMenu();
	void about();
	void showMoviesList();
	void showMovieInformation();
	void addMovieToArray(Movie movie);
	void redimArray(Movie*& array, int& sizeFrom, int newSize);
	void subAddRoom();

	std::string readString();
	int getint();
	double getdouble();
	Schedule subAddSchedule();
	Movie addMovie();
	
};

