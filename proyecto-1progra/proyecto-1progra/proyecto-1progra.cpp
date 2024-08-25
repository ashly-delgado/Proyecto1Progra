#include "Movie.h"
#include <iostream>
#include "Sale.h"
#include "Schedule.h"
#include "Cinema.h"
#include "Room.h"
#include <string>

void redimensionarArreglo(Movie*& array, int& sizeFrom, int newSize) {
	Movie* newArray = new Movie[newSize];
	int elementosACopiar = (newSize < sizeFrom) ? newSize : sizeFrom;
	std::memcpy(newArray, array, elementosACopiar * sizeof(Movie));
	delete[] array;
	array = newArray;
	sizeFrom = newSize;
}

int main() {
	int subOpcion = 0;
	int opcion;
	bool getOut = false;
	int contMovie = 0;
	int contSchedule = 0;
	int contRoom = 0;
	// definir un array de tipo de Movie
	// un instancia y la mete al arreglo
	Movie movie;
	Movie movies[10];
	Sale sale;
	Sale sales[10];
	Schedule schedule;
	Schedule schedules[10];
	Cinema cinema;
	Room room;
	Room rooms[10];
	std::string borrar;

	while (!getOut) {
		cinema.showMenu();
		opcion = cinema.getint();

		switch (opcion) {
		case 1:
			//opciones de archivos
			cinema.subShowFilesMenu();
			subOpcion = cinema.getint();
			if (subOpcion == 1) {
				cinema.about();
			}
			if (subOpcion == 2) {
				getOut = true;
			}
			break;
		case 2:
		
			cinema.subMenuMantenimiento();
			subOpcion = cinema.getint();
			if (subOpcion == 1) {
				cinema.addMovieToArray(cinema.addMovie());
				contMovie++;
			}

			if (subOpcion == 2) {
				cinema.subAddRoom();
				contRoom++;
			}

			if (subOpcion == 3) {
				schedules[contSchedule] = cinema.subAddSchedule();
				contSchedule++;
			}
			if (subOpcion == 4) {
				cinema.showMoviesList();
			}
			break;
		case 3:
			cinema.subMenuReserva();
			subOpcion = cinema.getint();
			if (subOpcion == 3) {
			
			}
			//reserva 

			break;
		case 4:
			cinema.subMenuVenta();
			subOpcion = cinema.getint();
			if (subOpcion == 4) {
				
			}
			//venta
			break;
		default:
			std::cout << "Opcion no aceptada. " << std::endl;
			break;

		}

	}
	return 0;
}
