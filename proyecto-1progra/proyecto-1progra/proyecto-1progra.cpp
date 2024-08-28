#include "Movie.h"
#include <iostream>
#include "Sale.h"
#include "Schedule.h"
#include "Cinema.h"
#include "Room.h"
#include <string>

int main() {
	int subOpcion = 0;
	int opcion;
	bool getOut = false;
	int contMovie = 0;
	int contSchedule = 0;
	int contRoom = 0;

	/*Movie movie;
	Movie movies[10];
	Sale sale;
	Sale sales[10];*/
	Schedule schedule;
	Schedule schedules[10];
	Cinema cinema;
	Room room;
	Room rooms[10];

	//switch de todo el menu
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
				cinema.subAddSchedule();
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
