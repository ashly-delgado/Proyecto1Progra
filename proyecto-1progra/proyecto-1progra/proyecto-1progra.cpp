#include "Movie.h"
#include <iostream>
#include "Sale.h"
#include "Schedule.h"
#include "Cinema.h"
#include "Room.h"
#include <string>
#include <chrono>

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
			cinema.maintenanceSubMenu();
			subOpcion = cinema.getInt();
			if (subOpcion == 1) {
				cinema.addMovieToArray(cinema.addMovie());
				contMovie++;
			}

			if (subOpcion == 2) {
				cinema.AddRoom();
				contRoom++;
			}

			if (subOpcion == 3) {
				cinema.AddSchedule();
				contSchedule++;
			}
			if (subOpcion == 4) {
				cinema.showMoviesList();
			}
			break;
		case 3:
			//reserva
			cinema.bookingSubMenu();
			subOpcion = cinema.getInt();
			if (subOpcion == 1) {
				if (cinema.reservation()) {

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
			cinema.saleMenu();
			subOpcion = cinema.getInt();
			if (subOpcion == 1) {
				cinema.fillSale();
			}
			if (subOpcion == 2) {
				cinema.listSale();
			}
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
