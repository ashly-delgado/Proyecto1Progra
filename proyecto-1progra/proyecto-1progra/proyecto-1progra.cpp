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


	Schedule schedule;
	Cinema cinema;
	
	//switch de todo el menu
	while (!getOut) {
		cinema.showMenu();
		opcion = cinema.getInt();

		switch (opcion) {
		case 1:
			//opciones de archivos
			cinema.subShowFilesMenu();
			subOpcion = cinema.getInt();
			if (subOpcion == 1) {
				cinema.about();
			}
			if (subOpcion == 2) {
				getOut = true;
			}
			break;
		case 2:
			cinema.subMenuMantenimiento();
			subOpcion = cinema.getInt();
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
			//reserva
			cinema.menuReservar();
			subOpcion = cinema.getInt();
			if (subOpcion == 1) {
				if (cinema.subMenuReserva()) {

				}
			}
			if (subOpcion == 2) {
				cinema.listSeats();
			}
			if (subOpcion == 3) {
				cinema.listBooking();
			}
			//venta 
			break;
		case 4:
			cinema.subMenuVenta();
			cinema.fillSale();
			
			break;
		case 5:
			getOut = true;
			break;

		default:
			std::cout << "Opcion no aceptada. " << std::endl;
			break;

		}

	}
	return 0;
}
