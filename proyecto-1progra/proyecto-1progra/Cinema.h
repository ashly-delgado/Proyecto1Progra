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
	bool subMenuReserva();
	void showMenu();
	void subMenuVenta();
	void subShowFilesMenu();
	void about();
	void showMoviesList();
	void addMovieToArray(Movie movie);
	void resizeArray(Movie*& array, int& sizeFrom, int newSize);
	void subAddRoom();

	std::string readString();
	int getint();
	double getdouble();
	void subAddSchedule();
	Movie addMovie();
	
};

