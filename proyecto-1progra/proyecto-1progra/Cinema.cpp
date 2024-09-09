#include "Cinema.h"
#include <iostream>
#include "Movie.h"
#include "Room.h"
#include <string>

//un vector estatico de 10 espacios, que son las peliculas
static int  NUM_MOVIESLIST = 10;
Movie* moviesList = new Movie[NUM_MOVIESLIST];

Cinema::Cinema() {
	Room room = Room();
	room.setNumber(1);
	room.setRowsQuantities(10);
	room.setSeatsPerRows(10);
	room.setNumberOfSeats(100);
	room.setPrice(3500);

	moviesList[0] = Movie("Moana", 2017, 140, "USA", 6, room);
	moviesList[1] = Movie("Rapidos y furiosos", 2021, 160, "Estados Unidos", 8, room);
	moviesList[2] = Movie("El conjuro", 2017, 150, "Estados Unidos", 7, room);
	moviesList[3] = Movie("El rey leon", 2020, 138, "Estados Unidos", 4, room);
	moviesList[4] = Movie("Frozen", 2021, 145, "Estados Unidos", 5, room);
	moviesList[5] = Movie("Deadpool", 2016, 156, "Canada", 7, room);
	moviesList[6] = Movie("Mufasa", 2024, 160, "Estados Unidos", 8, room);
	moviesList[7] = Movie("Bad Boys 4", 2024, 155, "Estados Unidos", 7, room);
	moviesList[8] = Movie("Escuadron suicida", 2021, 153, "Estados Unidos", 9, room);
	moviesList[9] = Movie("Elementos", 2023, 125, "Estados Unidos", 8, room);

}

//funcion de agregar mas peliculas al vector,llamando la funcion de redimencionar el vector
void Cinema::addMovieToArray(Movie movie) {
	int newNumber = NUM_MOVIESLIST + 1;
	resizeArray(moviesList, NUM_MOVIESLIST, newNumber);
	moviesList[newNumber - 1] = movie;
	NUM_MOVIESLIST = newNumber;
}

Cinema::~Cinema() {
}

//funcion de mostrar la lista de peliculas
void Cinema::showMoviesList() {
	std::cout << "======================================Peliculas disponibles========================================" << std::endl;
	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << "| Pelicula:" << " " << moviesList[i].getName() <<
			"|" << " " << "Anio:" << " " << moviesList[i].getYear() << "|" << " " <<
			"Tiempo:" << " " << moviesList[i].getCountry() << "|" << "" <<
			"Pais:" << " " << moviesList[i].getCountry() << "|" <<
			"Resenia:" << " " << moviesList[i].getReview() << "|" << std::endl;

		std::cout << "    Informacion de sala:" << "Numero de sala:" << moviesList[i].getRoom().getNumber() <<
			"Numero de asiento:" << moviesList[i].getRoom().getNumberOfSeats() <<
			"Precio:" << moviesList[i].getRoom().getPrice() << std::endl;
		Room room = moviesList[i].getRoom();

		std::cout << "HORARIOS: " << std::endl;
		for (int index = 0; index < room.getScheduleCounter(); index++) {
			std::cout << "Fecha de la pelicula: " << room.getSchedule(index).getDate() <<
				"  Hora de inicio: " << room.getSchedule(index).getStartHour() <<
				"  Hora de finalizacion: " << room.getSchedule(index).getEndHour() << std::endl;
		}
	}
	std::cout << "===================================================================================================" << std::endl;
}

//funcion de mostrar el menu principal
void Cinema::showMenu() {
	std::cout << "MENU DE NUEVA CINEMA SA:" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "1. Archivo" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "2. Mantenimiento" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "3. Reserva" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "4. Venta" << std::endl;
	std::cout << "------------------------\n";
	std::cout << "5. Salir" << std::endl;
	std::cout << "------------------------\n";
	std::cout << std::endl;
	std::cout << "Porfavor, seleccione una opcion:" << std::endl;
}

//funcion del submenu de mantenimiento
void Cinema::subMenuMantenimiento() {
	std::cout << "MANTENIMIENTO:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "1. Peliculas:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "2. Salas:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "3. Horarios:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "4. Peliculas Disponibles:" << std::endl;
	std::cout << "-------------------\n";
	std::cout << "Ingrese una opcion:" << std::endl;
}

//funcion del submenu de reserva
bool Cinema::subMenuReserva() {
	int number;
	int numberOfSchedule;
	std::cout << "RESERVA:" << std::endl;
	std::cout << "-------------------\n";

	std::cout << "PELICULAS:" << std::endl;
	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}

	std::cout << "A cual pelicula desea hacerle una reserva [digite un numero]:" << std::endl;
	number = getint();
	std::cout << "Sala en la que se exhibe la pelicula: " << moviesList[number].getRoom().getNumber() << std::endl;

	if (moviesList[number].getRoom().getScheduleCounter() == 0) {
		std::cout << "La pelicula no cuenta con horarios, Porfavor ingrese a la opcion de \"Mantenimiento\" y cree los horarios" << std::endl;
		return false;
	}
	std::cout << "Horarios disponibles:" << std::endl;
	for (int i = 0; i < moviesList[number].getRoom().getScheduleCounter(); i++ ) {
		std::cout << "Numero de horario ["<< i + 1<<"] " << moviesList[number].getName() << "Fecha: " << moviesList[number].getRoom().getSchedule(i).getDate()
			<< "Hora de inicio: " << moviesList[number].getRoom().getSchedule(i).getStartHour()
			<< "hora final: " << moviesList[number].getRoom().getSchedule(i).getEndHour();
	}
	std::cout << " A cual horario desea reservar:" << std::endl;
	numberOfSchedule = getint();
	moviesList[number].getRoom().getSchedule(numberOfSchedule -1).showSeats(moviesList[number].getRoom().getRowsQuantities(), moviesList[number].getRoom().getSeatsPerRows());

	return true;
}

//funcion del submenu de venta
void Cinema::subMenuVenta() {
	std::cout << "VENTA:" << std::endl;
	std::cout << "-------------------\n";
}

//funcion de redimencionar el vector de peliculas
void Cinema::resizeArray(Movie*& array, int& sizeFrom, int newSize) {
	Movie* newArr = new Movie[newSize];
	for (int i = 0; i < sizeFrom && i < newSize; ++i) {
		newArr[i] = array[i];
	}
	delete[] array;
	array = newArr;
}

//funcion de agregar pelicula
Movie Cinema::addMovie() {
	Room room = Room();
	Movie movie;
	int yearTheMovie = 0;
	int timeTheMovie = 0;
	int reviewTheMovie = 0;
	std::string nameTheMovie;
	std::string countryTheMovie;

	std::cout << "ingresar el nombre de la pelicula que desea agregar:" << std::endl;
	nameTheMovie = readString();
	movie.setName(nameTheMovie);

	std::cout << "ingresar el anio de la pelicula:" << std::endl;
	yearTheMovie = getint();
	movie.setYear(yearTheMovie);

	std::cout << "ingresar el tiempo de la pelicula:" << std::endl;
	timeTheMovie = getint();
	movie.setTime(timeTheMovie);

	std::cout << "ingresar el pais de la pelicula:" << std::endl;
	countryTheMovie = readString();
	movie.setCountry(countryTheMovie);

	movie.setRoom(room);
	std::cout << "Se a guardado la pelicula correctamente!!" << std::endl;
	std::cout << std::endl;
	return movie;
}

//funcion del submenu de archivos
void Cinema::subShowFilesMenu() {
	std::cout << "1. Acerca de " << std::endl;
	std::cout << "2. Salir " << std::endl;
}

//funcion de acerca de: creador del cinema
void Cinema::about() {
	std::cout << "==========================================\n";
	std::cout << "    BIENVENIDO A NUEVA CINEMA" << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "Creadora: Ashly Lizeth Delgado Morales" << std::endl;
	std::cout << std::endl;
	std::cout << "numero de identificacion: 604970068" << std::endl;
	std::cout << std::endl;
	std::cout << "      ES UN GUSTO ATENDERLOS" << std::endl;
	std::cout << "==========================================\n";
	std::cout << std::endl;
}
//funcion de agregar horarios
void Cinema::subAddSchedule() {
	Schedule schedule;
	int startHour = 0;
	int endHour = 0;
	std::string date;
	int number = 0;

	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}

	std::cout << "A cual pelicula desea ingresarle un horario:" << std::endl;
	number = getint();

	std::cout << "ingrese la fecha de la pelicula:" << std::endl;
	date = readString();
	schedule.setDate(date);

	std::cout << "ingresar la hora de inicio de la pelicula:" << std::endl;
	startHour = getint();
	schedule.setStartHour(startHour);

	std::cout << "ingresar la hora de finalizacion de la pelicula:" << std::endl;
	endHour = getint();
	schedule.setEndHour(endHour);

	if ((startHour >= 0 && startHour <= 24) && (endHour >= 0 && endHour <= 24)) {
		Room room = moviesList[number].getRoom();
		schedule.createSeatsMap(room.getRowsQuantities(), room.getSeatsPerRows());
		room.setSchedule(schedule);
		moviesList[number].setRoom(room);

		std::cout << "El horario de ha guardado con exito" << std::endl;
	}
	else {
		std::cout << "Error en las horas debe de ser entre (0 y 24)" << std::endl;
	}
}

//funcion de agregar sala
void Cinema::subAddRoom() {
	Room room;
	int number = 0;
	int numberMovie = 0;
	int numberOfSeats = 0;
	double price = 0;
	int rowsQuantities = 0;
	int seatsPerRows = 0;

	for (int i = 0; i < NUM_MOVIESLIST; i++) {
		std::cout << i << "| Pelicula:" << " " << moviesList[i].getName() << "|" << std::endl;
	}
	std::cout << "A cual pelicula desea ingresarle una sala:" << std::endl;
	numberMovie = getint();

	std::cout << "Numero de sala" << std::endl;
	number = getint();
	room.setNumber(number);

	std::cout << "Cantidad de filas" << std::endl;
	rowsQuantities = getint();
	room.setRowsQuantities(rowsQuantities);

	std::cout << "Digite la cantidad de asientos por filas: " << std::endl;
	seatsPerRows = getint();
	room.setSeatsPerRows(seatsPerRows);

	room.setNumberOfSeats(rowsQuantities * seatsPerRows);

	std::cout << "Precio" << std::endl;
	price = getdouble();
	room.setPrice(price);
	moviesList[numberMovie].setRoom(room);

	std::cout << "La sala se guardo con exito!!" << std::endl;

}

//funcion para leer una cadena de texto
std::string Cinema::readString() {
	std::string read;
	std::getline(std::cin, read);
	return read;
}

//funcion para pasar a enteros
int Cinema::getint() {
	int number;
	bool notNumber = true;
	while (notNumber) {
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Favor Digite un Entero." << std::endl;
			notNumber = true;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			notNumber = false;
		}
	}
	return number;
}

//funcion para pasar a decimal
double Cinema::getdouble() {
	double number;
	bool notNumber = true;
	while (notNumber) {
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Favor digitar un numero." << std::endl;
			notNumber = true;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			notNumber = false;
		}
	}
	return number;
}
